#include<bits/stdc++.h>
#define maxn 200020

using namespace std;
typedef long long ll;

ll x[maxn];
int dis[maxn];

vector<int> e[maxn];
int ans;
bool vis[maxn];

void solve(int sta)
{
    memset(dis,0x3f3f3f,sizeof(dis));
    dis[sta]=0;
    queue<int> q;
    q.push(sta);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v: e[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

void dfs(int u,int fa,int dep,int st)
{
    if(dep>dis[st]) return;
    for(int v: e[u])
    {
        if(v==fa) continue;
        if(v==st)
        {
            if(dep==dis[st]) ans++;
            return;
        }
        else dfs(v,u,dep+1,st);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        if(n<=5000)
        {
            for(int i=1;i<=n;i++) e[i].clear();
            for(int i=1;i<=n;i++) cin>>x[i];
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d)
                    {
                        e[i].push_back(j);
                        e[j].push_back(i);
                    }
                }
            }
            int res=0;
            for(int i=1;i<=n;i++)
            {
                solve(i);
                for(int j=1;j<=n;j++)
                {
                    if(i==j) continue;
                    if(dis[j]==0x3f3f3f) continue;
                    ans=0;
                    dfs(i,0,1,j);
                    if(ans==2)
                    {
                        res++;
                    }
                }
            }
            res/=2;
            cout<<res<<'\n';
        }
        else cout<<0<<'\n';
    }
    return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/