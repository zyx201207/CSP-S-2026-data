#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <algorithm>

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int32_t num, kind;
    std::cin>>num>>kind;
    std::vector<int32_t> nums(num+1);
    for(int32_t i = 1;i<=num;i++)
    {
        std::cin>>nums[i];
    }
    std::vector<int32_t> result(kind+1);
    for(int32_t i = 1;i<=num;i++)
    {
        std::vector<int32_t> tasks;
        for(int32_t j = i;j<=num;j++)
        {
            if(std::binary_search(tasks.begin(),tasks.end(),nums[j]))
            {
                int32_t start = std::lower_bound(tasks.begin(),tasks.end(),nums[j])-tasks.begin();
                int32_t len = tasks.size();
                for(int32_t k = start;k<len;k++)
                {
                    tasks.pop_back();
                }
            }
            tasks.push_back(nums[j]);
        }
        for(int32_t task : tasks)
        {
            result[task]++;
        }
    }
    for(int32_t i = 1;i<result.size();i++)
    {
        std::cout<<result[i]<<" ";
    }
    return EXIT_SUCCESS;
}
