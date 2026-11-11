/*
15:27 da yang li quan guo: 100pts
15:32 fa xian you dian ka chang?
15:36 zao le ge da yang li, neng guo
nan du: huang
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=555,M=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M],t[M],e[N][N],dp[N][N];
vector<int>ti[M],tt[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        int tot;
        cin>>tot;
        for(int j=1;j<=tot;++j)
        {
            int to,v;
            cin>>to>>v;
            t[to]++;
            ti[to].push_back(i);
            tt[to].push_back(v);
        }
    }
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<t[i];++j)
        {
            for(int k=j+1;k<t[i];++k)
            {
                e[ti[i][j]][ti[i][k]]=min(e[j][k],tt[i][j]+tt[i][k]);
                e[ti[i][k]][ti[i][j]]=e[ti[i][j]][ti[i][k]];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j]=e[i][j];
        }
        dp[i][i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    while(q--)
    {
        int x,y,ans=INF;
        cin>>x>>y;
        for(int i=0;i<t[x];++i)
        {
            for(int j=0;j<t[y];++j)
            {
                ans=min(ans,dp[ti[x][i]][ti[y][j]]+tt[x][i]+tt[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    //cout<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    return 0;
}