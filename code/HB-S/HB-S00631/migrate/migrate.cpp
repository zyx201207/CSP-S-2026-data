#include<bits/stdc++.h>
#define int long long
#define PII pair<long,long>
#define Fi first
#define Se second
using namespace std;
const int N=2e6+10;
int c,t,x[N],n,d,vis[N],cnt[N],ans;
vector<int> edge[N];
void subtask1()//1-6
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i],edge[i].clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(abs(x[i]-x[j])<=d) edge[i].push_back(j);
        }
    }
    int dis[510];
    ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dis[j]=1e18,vis[j]=0,cnt[j]=0;
        dis[i]=0;
        cnt[i]=1;
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        pq.push({0,i});
        while(pq.size())
        {
            int u=pq.top().Se;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int v:edge[u])
            {
                if(dis[u]+1<dis[v]) dis[v]=dis[u]+1,cnt[v]=cnt[u],pq.push({dis[v],v});
                else if(dis[u]+1==dis[v]) cnt[v]++;
            }
        }
        for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
    }
    cout<<ans/2<<endl;
}
void subtaskA()
{
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int D=x[2]-x[1],r=d/D;
    if(r==0||r==1)
    {
        cout<<0<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        ans=ans+(i+r+r-1<=n);
    }
    cout<<ans<<endl;
}
void solve()
{
    if(1<=c&&c<=10) subtask1();
    if(11<=c&&c<=12) subtaskA();
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
/*
思路1-6暴力跑dij最短路计数，暴力连边
特殊性质a，令r=D/d（D为d，d为公差），当且仅当两个点编号差k=r+r-1时可以连边
RP++
I LOVE CCF
*/
/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
