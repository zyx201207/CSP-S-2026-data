#include <bits/stdc++.h>
using namespace std;
const int N=15;
int c;
int n,K;
vector<int> e[N];
bool book[N],vis[N];
void dfs(int x,int fa)
{
    vis[x]=true;
    for(int y:e[x])
    {
        if(y==fa || !book[y])continue;
        dfs(y,x);
    }
}
bool check(int mask)
{
    int cnt=0;
    for(int i=0;i<n;i++)if(mask&(1<<i))cnt++;
    if(cnt!=K)return false;

    vector<int> city;
    memset(vis,false,sizeof vis);
    memset(book,false,sizeof book);
    for(int i=0;i<n;i++)if(mask&(1<<i))city.push_back(i+1),book[i+1]=true;
    int cnt_dfs=0;
    for(int s:city)
        if(!vis[s])
        {
            cnt_dfs++;
            dfs(s,0);
        }
    if(cnt_dfs>2)return false;
    return true;
}
int d(int S)
{
    if(book[S]==true)return 0;

    queue<pair<int,int> > q;
    memset(vis,false,sizeof vis);
    q.push({S,0});
    vis[S]=true;
    while(!q.empty())
    {
        auto h=q.front();q.pop();
        int u=h.first;
        for(int v:e[u])
        {
            if(vis[v])continue;
            if(book[v])return h.second+1;
            q.push({v,h.second+1});
        }
    }
}
int calc(int mask)
{
    memset(book,false,sizeof book);
    for(int i=0;i<n;i++)if(mask&(1<<i))book[i+1]=true;

    int res=-1e9;
    for(int i=1;i<=n;i++)
        res=max(res,d(i));
    return res;
}
void clear()
{
    for(int i=1;i<=n;i++)e[i].clear();
}
void solve()
{
    clear();
    cin>>n>>K;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=1e9;
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(!check(mask))continue;
        ans=min(ans,calc(mask));
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>c>>T;
    while(T--)solve();
    return 0;
}
/*
cd hub
ulimit -s unlimited
g++ hub.cpp -o hub -O2 -std=c++14 -static -Wall
time ./hub
*/