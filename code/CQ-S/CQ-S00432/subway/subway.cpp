#include<bits/stdc++.h>
using namespace std;
namespace RST
{
    long long _[500005];
    vector<pair<int,long long> >bus[500005];
    long long f1[505][505];
    void solve()
    {
        int c,n,m,d,q;
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
        {
            cin>>_[i];
        }
        for(int i=1;i<=n;i++)
        {
            int len;
            cin>>len;
            for(int j=1;j<=len;j++)
            {
                int x,y;
                cin>>x>>y;
                bus[x].emplace_back(i,y);
            }
        }
        memset(f1,0x3f,sizeof(f1));
        for(int i=1;i<=n;i++)
        {
            f1[i][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<bus[i].size();j++)
            {
                for(int k=j+1;k<bus[i].size();k++)
                {
                    int u=bus[i][j].first,v=bus[i][k].first;
                    f1[v][u]=f1[u][v]=min(f1[u][v],bus[i][j].second+bus[i][k].second);
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    f1[i][j]=min(f1[i][j],f1[i][k]+f1[k][j]);
                }
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            long long ans=1e18;
            for(auto i:bus[x])
            {
                for(auto j:bus[y])
                {   
                    ans=min(ans,f1[i.first][j.first]+i.second+j.second);
                }
            }
            cout<<ans+_[x]+_[y]<<"\n";
        }
        return ;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)
    {
        RST::solve();
    }
    return 0;
}//g++ -o subway.exe subway.cpp -lm -O2 -std=c++14 -Wall -Wl,--stack=1000000000
//subway.exe >subway.out < ..\subway\subway7.in
//fc subway.out ..\subway\subway7.ans
//最结合生活实际的一集 那个w 有什么用
//才发现sub倒过来是bus