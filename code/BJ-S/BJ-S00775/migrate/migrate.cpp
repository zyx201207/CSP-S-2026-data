#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c, t, n, D, x[N], cnt[N], d[N], ind[N];
ll ans;
vector<int> e[N], tr[N];
int bfs(int s)
{
    for(int i=1;i<=n;i++)
    {
        tr[i].clear();
        d[i]=1e18;
        cnt[i]=ind[i]=0;
    }
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(q.size())
    {
        int u=q.front();q.pop();
        cnt[u]=1;
        for(int v : e[u])
        {
            if(d[v]>d[u]+1)
            {
                tr[u].push_back(v);
                q.push(v);
                d[v]=d[u]+1;
                ind[v]++;
            }
            else if(d[v]==d[u]+1)
            {
                tr[u].push_back(v);
                ind[v]++;
            }
        }
    }
    q.push(s);
    int t=0;
    while(q.size())
    {
        int u=q.front();q.pop();
        for(int v : tr[u])
        {
            q.push(v);
            cnt[v]=cnt[u]*ind[v];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==2) t++;
    }
    return t;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>D;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            e[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(abs(x[i]-x[j])>D) continue;
                e[i].push_back(j);
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=bfs(i);
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
