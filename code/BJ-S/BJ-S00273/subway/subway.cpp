#include<bits/stdc++.h>
using namespace std;
struct node{
    long long id,cost;
};
long long c,n,m,d,p,w[500005],k[505],zx[25];
int a[505][500005],t[505][500005];
long long cnt;
bool vis[500005];
vector<long long> f[505];
void bfs(int x,int y)
{
    int cnt2=1;
    memset(vis,0,sizeof(vis));
    queue<node> q;
    q.push({zx[cnt2],w[x]});
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(vis[u.id]) continue;
        vis[u.id]=1;
        long long s=0;
        for(int i=0;i<f[u.id].size();i++)
        {
            s+=t[u.id][f[u.id][i]];
            if(f[u.id][i]==y)
            {
                cnt=min(cnt,u.cost+s+w[y]);
            }
            q.push({zx[++cnt2],u.cost+s});
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            f[i].push_back(a[i][j]);
        }
    }
    while(p--)
    {
        long long x,y;
        cin>>x>>y;
        cnt=1e9;
        long long cnt1=0;
        memset(zx,0,sizeof(zx));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            long long tx=0,ty=0;
            bool fx=0,fy=0;
            for(int j=1;j<=k[i];j++)
            {
                if(!fx) tx+=t[i][j];
                if(!fy) ty+=t[i][j];
                if(a[i][j]==x) fx=1,zx[++cnt1]=i,tx-=t[i][j];
                if(a[i][j]==y) fy=1;
            }
            if(fx&&fy)
            {
                cnt=min(cnt,ty-tx);
            }
        }
        if(cnt!=1e9)
        {
            cout<<cnt+w[x]+w[y]<<'\n';
            continue;
        }
        bfs(x,y);
        cout<<cnt<<'\n';
    }
}
