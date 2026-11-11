#include<bits/stdc++.h>
int n,m,d,q,ans,w[500001],k[501],x[100001],y[100001];
std::vector<int>a[501],t[501];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::cin>>ans>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        std::cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        std::cin>>k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for(int j=1;j<=k[i];j++)
        {
            std::cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        std::cin>>x[i]>>y[i];
    }
    std::cout<<ans;
    return 0;
}
