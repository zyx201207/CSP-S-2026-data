#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6+5;
int c,T;
int n;
ll m;
ll a[MAXN];
int dis[MAXN];
ll f[MAXN];
vector<int>adj[MAXN];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    f[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v] = dis[u]+1;
                f[v] = f[u];
                q.push(v);
            }
            else if(dis[v]==dis[u]+1)
            {
                f[v]+=f[u];
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i = 1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n<=2)
        {
            cout<<"0\n";
            continue;
        }
        if(m>=a[n]-a[1])
        {
            cout<<"0\n";
            continue;
        }
        if(c>=11&&c<=12)
        {
            ll d = a[2]-a[1];
            if(m<d*2)cout<<"0\n";
            else
            {
                ll num = m/d;
                cout<<n-2*num+1<<"\n";
            }
        }
        else
        {
            for(int i = 1;i<=n;i++)
            {
                adj[i].clear();
            }
            for(int i = 1;i<=n;i++)
            {
                for(int j = i-1;j>=1;j--)
                {
                    if(a[i]-a[j]>m)break;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            ll ans = 0;
            for(int i = 1;i<=n;i++)
            {
                memset(dis,0x3f,sizeof(dis));
                memset(f,0,sizeof(f));
                bfs(i);
                for(int j = 1;j<=n;j++)
                {
                    if(f[j]==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans/2<<"\n";
        }
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}