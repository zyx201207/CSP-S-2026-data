#include <bits/stdc++.h>
using namespace std;
const int N=510,M=910;
int c,n,m,d,q;
struct node
{
    int u,time;//t:zhanting->zhantai
};
int w[N];//ditiekou->zhanting
int cnt[N];
vector<node>v[M];
int vis[N],ans=0;
void dfs(int s,int t)
{
    memset(cnt,0,sizeof cnt);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==t) return;
        for (auto i:v[x])
        {
            if(!vis[i.u])
            {
                vis[i.u]=1;
                ans=ans+i.time+cnt[i.u];
                dfs(i.u,t);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k,last=1;
        cin>>k;
        while(k--)
        {
            int vv,tt;
            cin>>vv>>tt;
            if(vv==last) cnt[vv]=tt;
            v[vv].push_back({last,tt});
            v[last].push_back({vv,tt});
            last=vv;
        }
    }
    while(q--)
    {
        int s,t;
        ans=0;
        cin>>s>>t;
        ans+=(w[s]+w[t]);
        memset(vis,0,sizeof vis);
        dfs(s,t);
        cout<<ans<<endl;
    }
    return 0;
}

