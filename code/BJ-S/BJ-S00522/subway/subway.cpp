#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
const long long inf=1e18;
int c,n,m,d,q;
int k[maxn];
long long ans;
long long w[maxm];
long long dis[maxn][maxn];
struct node{int a;long long t;};
vector<node>g[maxn];
vector<node>f[maxm];
bool cmp(node x,node y)
{
    return x.a<y.a;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            long long y;
            cin>>x>>y;
            g[i].push_back((node){x,y});
        }
        sort(g[i].begin(),g[i].end(),cmp);
        for(int j=0;j<k[i];j++)
        {
            int x=g[i][j].a;
            long long y=g[i][j].t;
            f[x].push_back((node){i,y});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            long long res=inf;
            for(int u=0,v=0;u<g[i].size() && v<g[j].size();u++)
            {
                while(v<g[j].size() && g[j][v].a<g[i][u].a) v++;
                if(v<g[j].size() && g[j][v].a==g[i][u].a) res=min(res,g[j][v].t+g[i][u].t);
            }
            if(res!=inf) dis[i][j]=dis[j][i]=res;
            //cout<<i<<" "<<j<<" "<<res<<"\n";
        }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    //for(int i=1;i<=n;i++)
    //    for(int j=1;j<=n;j++)
    //        cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long res=inf;
        for(int i=0;i<f[x].size();i++)
            for(int j=0;j<f[y].size();j++)
            {
                int o=f[x][i].a;
                int p=f[y][j].a;
                res=min(res,dis[o][p]+f[x][i].t+f[y][j].t);
            }
        res+=w[x];
        res+=w[y];
        cout<<res<<"\n";
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
