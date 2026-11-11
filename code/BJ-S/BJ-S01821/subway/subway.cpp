#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+10,M=5e2+10,inf=1e18;
int W[N],dis[M][M];
vector<int>e[N],w[N];
void upd(int x,int &y){y=min(x,y);}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int c,n,m,d,q;
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>W[i];
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,t;
            cin>>x>>t;
            e[x].push_back(i);
            w[x].push_back(t);
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            dis[i][j]=(i==j?0:inf);
    for(int i=1;i<=n;i++)
        for(int j=0;j<e[i].size();j++)
            for(int k=0;k<e[i].size();k++)
                upd(w[i][j]+w[i][k],dis[e[i][j]][e[i][k]]);
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
            {
                upd(dis[i][k]+dis[k][j],dis[i][j]);
                upd(dis[i][k]+dis[k][j],dis[j][i]);
            }
    for(int i=1;i<=q;i++)
    {
        int u,v,ans=inf;
        cin>>u>>v;
        for(int i=0;i<e[u].size();i++)
        {
            for(int j=0;j<e[v].size();j++)
            {
                ans=min(ans,dis[e[u][i]][e[v][j]]+w[u][i]+w[v][j]);
            }
        }
        ans+=W[u]+W[v];
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/