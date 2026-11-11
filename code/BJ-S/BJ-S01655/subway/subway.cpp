#include<iostream>
#include<vector>
#define int long long
using namespace std;
int cid,n,m,d,q;
const int nr=510,mr=5e5+10;
int w[mr];
struct node{
    int x,t;
};
vector<node>v[mr];
int g[nr][nr];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>cid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,t;
            cin>>x>>t;
            v[x].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)g[i][j]=g[j][i]=1e18;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
            for(int k=j+1;k<v[i].size();k++)
            {
                int jx=v[i][j].x,jt=v[i][j].t;
                int kx=v[i][k].x,kt=v[i][k].t;
                g[jx][kx]=g[kx][jx]=min(g[jx][kx],jt+kt);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<g[i][j]<<" ";cout<<endl;
    }*/
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int minn=1e18;
        for(int i=0;i<v[x].size();i++)
            for(int j=0;j<v[y].size();j++)
            {
                int ix=v[x][i].x,it=v[x][i].t;
                int jx=v[y][j].x,jt=v[y][j].t;
                minn=min(minn,it+jt+g[ix][jx]);
            }
        cout<<minn+w[x]+w[y]<<'\n';
    }
    return 0;
}
