#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=1e6+5;
int n,k,T,C,dis[15][15],box[15],vis[15],ans=INT_MAX,ds[N],maxx;
vector<int> v[N];
void dfs(int rt,int x,int f)
{
    for(auto to:v[x])
    {
        if(to==f) continue;
        dis[rt][to]=dis[rt][x]+1;
        // cout<<rt<<' '<<to<<' '<<x<<'\n';
        dfs(rt,to,x);
    }
    return;
}
queue<int> q;
void bfs(int x)
{
    q.push(x);
    while(!q.empty())
    {
        int u=q.front();
        vis[u]=1;
        q.pop();
        for(auto to:v[u]) if(box[to]&&!vis[to]) q.push(to);
    }
    return;
}
void dfs2(int x) 
{
    if(x>n)
    {
        int j,sum=0,i;
        F(i,1,n) sum+=box[i],vis[i]=0;
        if(sum!=k) return;
        sum=0;
        F(i,1,n) if(box[i]&&!vis[i]) 
        {
            bfs(i);
            sum++;
        }   
        if(sum>2) return;
        int tmp=0;
        F(i,1,n) 
        {
            int nw=INT_MAX;
            F(j,1,n) if(box[j]) nw=min(nw,dis[i][j]);
            tmp=max(tmp,nw);
        }
        ans=min(ans,tmp);
        return;
    }
    dfs2(x+1);
    box[x]=1;
    dfs2(x+1);
    box[x]=0;
    return;
}
void ddfs(int x,int f)
{
    if(ds[maxx]<ds[x]) maxx=x;
    for(auto to:v[x])
    {
        if(to==f) continue;
        ds[to]=ds[x]+1;
        // cout<<rt<<' '<<to<<' '<<x<<'\n';
        ddfs(to,x);
    }
    return;
}
void solve()
{
    cin>>n>>k;
    int i;
    F(i,1,n) v[i].clear();
    ans=INT_MAX;
    F(i,1,n-1)  
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(C<=3)
    {
        memset(dis,0,sizeof dis);
        F(i,1,n) dfs(i,i,0);
        dfs2(1);
        cout<<ans<<'\n';
    }
    else 
    {
        memset(ds,0,sizeof ds);
        maxx=1;
        ddfs(1,0);
        int a=maxx;
        ds[a]=0;
        ddfs(a,0);
        cout<<(ds[maxx]-1)/4+1<<'\n';
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    cin>>C>>T;
    while(T--) {solve();}
}