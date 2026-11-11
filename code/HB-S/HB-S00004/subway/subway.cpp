#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll INF=1000000000000000005;
ll w[N],f[N][N];
struct T
{
    ll x,w;
};
vector<T>v[N];
void run1()
{
    int n,m,d,q;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)f[i][j]=INF;
    }
    for(int i=1;i<=m;i++)f[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,c;
            cin>>x>>c;
            v[i].push_back({x,c});
        }
        for(int j=0;j<v[i].size();j++)
        {
            for(int k=j+1;k<v[i].size();k++)
            {
                f[v[i][j].x][v[i][k].x]=
                        min(f[v[i][j].x][v[i][k].x],
                        v[i][j].w+v[i][k].w);
                f[v[i][k].x][v[i][j].x]=f[v[i][j].x][v[i][k].x];
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<'\n';
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int id;
    cin>>id;
    if(id>=0&&id<=11)
    {
        run1();
        return 0;
    }
    return 0;
}