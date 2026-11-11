#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <queue>
#include <climits>

#define INF INT_MAX

struct Node
{
    int32_t vertex;
    int32_t time;
};

struct _Node
{
    int32_t vertex, pos;
};

int main()
{
    freopen("subway.in","r", stdin);
    freopen("subway.out","w",stdout);
    int32_t tmp, num_len, num_vertex, _tmp, t;
    std::cin>>tmp>>num_len>>num_vertex>>_tmp>>t;
    std::vector<int32_t> _time(num_vertex+1);
    for(int32_t i = 1;i<=num_vertex;i++)
    {
        std::cin>>_time[i];
    }
    std::vector<std::vector<Node>> nums(num_len+1);
    std::vector<std::vector<int32_t>> next(num_len+1,std::vector<int32_t>(num_vertex+1));
    for(int32_t i = 1;i<=num_len;i++)
    {
        int32_t num;
        std::cin>>num;
        nums[i].resize(num+1);
        for(int32_t j = 1;j<=num;j++)
        {
            std::cin>>nums[i][j].vertex>>nums[i][j].time;
            next[i][nums[i][j - 1].vertex] = j;
        }
    }
    while(t--)
    {
        int32_t start, end;
        std::cin>>start>>end;
    }
    while(t--)
    {
        int32_t start, end;
        std::cin>>start>>end;
        std::vector<int32_t> dist(num_vertex+1, INF);
        dist[start] = 0;
        std::vector<bool> visited(num_vertex+1,false);
        visited[start] = true;
        std::queue<_Node> q;
        for(int32_t i = 1;i<=num_len;i++)
        {
            q.push({start,i});
        }
        while(!q.empty())
        {
            int32_t from = q.front().vertex;
            int32_t pos = q.front().pos;
            q.pop();
            if(from == end)
            {
                break;
            }
            int32_t _next = next[pos][from];
            int32_t _to = nums[pos][_next].vertex;
            dist[_to] = std::min(dist[_to],dist[from]+nums[pos][from].time);
            if(!visited[_to])
            {
                visited[_to] = true;
                q.push({_to,pos});
            }
            for(int32_t i = 1;i<=num_len;i++)
            {
                int32_t j = next[i][from];
                int32_t to = nums[i][j].vertex;
                dist[to] = std::min(dist[to],dist[from]+nums[i][j].time+nums[i][from].time);
                if(!visited[to])
                {
                    visited[to] = true;
                    q.push({to,i});
                }
            }
        }
        std::cout<<dist[end]+_time[start]+_time[end];
    }
    return EXIT_SUCCESS;
}
