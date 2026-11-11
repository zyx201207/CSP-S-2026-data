#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,N1=1e3+5;
int n,k;
int dist[N],ans;
vector<int> adj[N];
int a[N1][N1],b[N1];
void bfs(int u,int mid)
{
    queue<int> q;
    q.push(u);
    for(int i=1;i<=n;i++) dist[i]=-1;
    dist[u]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(dist[cur]<=mid) a[u][cur]=1;
        else a[u][cur]=0;
        for(auto v:adj[cur])
        {
            if(dist[v]==-1)
            {
                dist[v]=dist[cur]+1;
                q.push(v);
            }
        }
    }
    return ;
}
bool check(int mid)
{
    for(int i=1;i<=n;i++)
    {
        bfs(i,mid);
    }
    for(int i=1;i<=n;i++) b[i]=a[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[j]=b[j]&a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1)
        {
            cnt++;
            if(cnt>=2) return true;
        }
    }
    return false;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int l=0,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
    return 0;
}
