#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5;
const int N=505;
ll w[M];
struct pp
{
    int op;
    ll t;
};
vector<pp> tu[N];
ll dis[505][505];
const ll inf=0x3f3f3f3f;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int op;
            ll t;
            cin>>op>>t;
            tu[i].push_back({op,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(i==j) dis[i][j]=0;
            else
            {
                dis[i][j]=inf;
                dis[j][i]=inf;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)tu[i].size();j++)
        {
            for(int k=j;k<(int)tu[i].size();k++)
            {
                int a=tu[i][j].op,b=tu[i][k].op;
                ll t1=tu[i][j].t,t2=tu[i][k].t;
                if(a==b)
                {
                    dis[a][b]=0;
                    dis[b][a]=0;
                    continue;
                }
                dis[a][b]=min(dis[a][b],t1+t2);
                dis[b][a]=dis[a][b];
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dis[i][k]!=inf&&dis[k][j]!=inf) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int begin,end;
        cin>>begin>>end;
        ll ans=w[begin]+w[end]+dis[begin][end];
        cout<<ans<<"\n";
    }
    return 0;
}