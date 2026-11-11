#include<bits/stdc++.h>
int n,m,ans,a[500001];
std::map<long long,int>map;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        map[a[i]]++;
    }
    for(auto x:map)
    {
        ans=std::max(ans,x.second);
    }
    std::cout<<ans;
    return 0;
}
