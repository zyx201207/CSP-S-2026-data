#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define maxn 500000

int a[maxn];
int n,d;


vector<pii> e[maxn];
int dis[maxn],vis[maxn];
priority_queue<pii ,vector< pii >,greater< pii > >que;

//g++ subway.cpp -o subway -o2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion

void dijkstra(int st)
{
    for(int i=1;i<=400000;i++) dis[i]=1000000000000000,vis[i]=0;
    while(!que.empty()) que.pop();
    dis[st]=0;
    que.push({0,st});
    while(!que.empty())
    {
        int now=que.top().second;
        que.pop();
        if(vis[now]==1) continue;
        vis[now]=1;
        for(int i=0;i<(int)e[now].size();i++)
        {
            int to=e[now][i].first,payw=e[now][i].second;
            if(dis[to]>dis[now]+payw)
            {
                dis[to]=dis[now]+payw;
                que.push({dis[to],to});
            }
        }
    }
    return ;
}



int cnt[maxn],ans=0;

void dfs(int now,int dep)
{
    if(dep!=dis[now]) return ;
    cnt[now]++;
    
    for(int i=now+1;i<=n;i++)
    {
        if(abs(a[i]-a[now])>d) break;     
        dfs(i,dep+1);    
    }
}

void solve()
{

    cin>>n>>d;ans=0;
    for(int i=1;i<=n+10;i++)
    {
        a[i]=0;
        e[i].clear();
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(abs(a[i]-a[j])>d) break; 
            e[i].push_back({j,1});
        }
    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
        for(int j=1;j<=n;j++)
            cnt[i]=0;
        dfs(i,0);
// for(int s=1;s<=n;s++) cerr<<dis[s]<<" ";
// cerr<<endl;
// for(int s=1;s<=n;i++) cerr<<cnt[s]<<" ";
// cerr<<endl;   
        for(int j=1;j<=n;j++)
            if(cnt[i]==2) ans++; 
    }
    

    cout<<ans;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout)
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        solve();
    }
return 0;
}