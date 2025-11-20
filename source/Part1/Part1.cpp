#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int i = 0;
    for (auto& schedule : schedules)
    {
        std::cout << "출근희망시간" << schedule << std::endl;
        int nowDay = startday;
        bool lated = false;
        auto& logs = timelogs[i];

        for (auto& timelog : logs)
        {
            std::cout << "출근시간:" << timelog << ":" << nowDay << std::endl;

            if (nowDay >= 6)
            {
                nowDay++;
                if (nowDay > 7)
                {
                    nowDay = 1;
                }
                continue;
            }

            int endTime = schedule + 10;
            int endHour = endTime / 100;
            int endMin = endTime / 60;

            if (endTime % 100 >= 60) {
                endTime = (endHour + 1) * 100 + (endTime % 100 - 60);
            }

            if (timelog > (schedule + 10))
            {
                std::cout << "지각이다" << timelog << std::endl;
                std::cout << ":" << nowDay << std::endl;

                lated = true;
                break;
            }

            nowDay++;
        }       
        
        if (lated == false)
        {
            answer++;
        }
        ++i;
    }
    return answer;
}

int main()
{
    vector<int> schedules = { 750, 800, 1100 };
    vector<int> logs1 = { 710, 2359, 1050, 700, 650, 631, 659 };
    vector<int> logs2 = { 800, 801, 805, 800, 759, 810, 809 };
    vector<int> logs3 = { 1105, 1001, 1002, 600, 1059, 1001, 1100 };
    vector<vector<int>> timelogs;  
    timelogs.push_back(logs1);
    timelogs.push_back(logs2);
    timelogs.push_back(logs3);
    int startday = 5;
    solution(schedules, timelogs, startday);


}