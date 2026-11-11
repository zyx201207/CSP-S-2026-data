#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;
const int N=505,M=5e5+5;
struct sub
{
    int id;
    ll t;
};
int c,n,m,d,q;
ll w[M],k[M],s[N][N];
vector<sub>b[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(s,-1,sizeof(s));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            ll y;
            cin>>x>>y;
            b[x].eb(sub{i,y});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            for(int k=j+1;k<b[i].size();k++)
            {
                sub x=b[i][j],y=b[i][k];
                s[x.id][y.id]=s[y.id][x.id]=(s[x.id][y.id]==-1?(x.t+y.t):(min(s[x.id][y.id],x.t+y.t)));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        s[i][i]=0;
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(i==k||j==k||s[i][k]==-1||s[j][k]==-1)
                {
                    continue;
                }
                ll dis=s[i][k]+s[j][k];
                s[i][j]=s[j][i]=(s[i][j]==-1?dis:min(s[i][j],dis));
            }
        }
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        ll mn=2e18;
        for(int i=0;i<b[u].size();i++)
        {
            for(int j=0;j<b[v].size();j++)
            {
                int x=b[u][i].id,y=b[v][j].id;
                if(s[x][y]==-1)
                {
                    continue;
                }
                ll z=s[x][y]+b[u][i].t+b[v][j].t;
                if(mn>z)
                {
                    mn=z;
                }
            }
        }
        cout<<mn+w[u]+w[v]<<endl;
    }
    return 0;
}
