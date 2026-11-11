#include<bits/stdc++.h>
int t,n,a[100001];
long long d,ans;
void dfs(long long s,long long u,long long cnt,std::map<long long,std::vector<long long>>map1,std::set<long long>v,std::map<long long,std::map<long long,std::pair<long long,long long>>>&map2)
{
    v.insert(u);
    for(long long x:map1[u])
    {
        if(v.count(x))
        {
            continue;
        }
        if(map2[s][x].second==0||map2[s][x].first>cnt+1)
        {
            map2[s][x]={cnt+1,1};
            map2[x][s]={cnt+1,1};
        }
        else if(map2[s][x].first==cnt+1)
        {
            map2[s][x].second++;
            map2[x][s].second++;
        }
        dfs(s,x,cnt+1,map1,v,map2);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::cin>>ans>>t;
    while(t--)
    {
        ans=0;
        std::map<long long,std::vector<long long>>map1;
        std::set<long long>v;
        std::map<long long,std::map<long long,std::pair<long long,long long>>>map2;
        std::cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            std::cin>>a[i];
            map1[a[i]];
            for(int j=1;j<i;j++)
            {
                if(a[i]-a[j]<=d)
                {
                    map1[a[j]].push_back(a[i]);
                    map1[a[i]].push_back(a[j]);
                }
            }
        }
        for(auto x:map1)
        {
            dfs(x.first,x.first,0,map1,v,map2);
            v.insert(x.first);
        }
        for(auto x:map2)
        {
            for(auto y:x.second)
            {
                if(y.second.second==2)
                {
                    ans++;
                }
            }
        }
        std::cout<<ans/2<<"\n";
    }
    return 0;
}
