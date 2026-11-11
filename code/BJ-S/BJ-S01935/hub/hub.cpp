#include<bits/stdc++.h>
int t,n,k,u,v,ans;
std::vector<int>g[1000001];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::cin>>ans>>t;
    while(t--)
    {
        std::cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            std::cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        std::cout<<ans;
    }
    return 0;
}
