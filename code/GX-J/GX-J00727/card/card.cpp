#include <iostream>
#include <cstdio>
#include <vector>
int n,m;
std::vector<int> arr;
std::vector<int> f(int x)
{
    std::vector<int> aaa2;
    std::vector<bool> vis(m,false);
    std::vector<int> place(m,0);
    for(int i = x;i<n;i++)
    {
        if(vis[arr[i]])
        {
            for(int j=place[arr[i]];j<(int)aaa2.size();j++)
            {
                vis[aaa2[j]] = false;
            }
            aaa2.erase(aaa2.begin()+place[arr[i]],aaa2.end());
        }
        aaa2.push_back(arr[i]);
        vis[aaa2.back()] = true;
        place[arr[i]] = aaa2.size()-1;
    }
    return aaa2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        arr.push_back(x);
    }

    std::vector<int> aaa(m+1,0);
    for(int i=0;i<n;i++)
    {
        for(int i:f(i))
        {
            aaa[i]++;
        }
    }
    aaa.erase(aaa.begin());
    for(int i:aaa){
        std::cout<<i<<' ';
    }
    return 0;
}
