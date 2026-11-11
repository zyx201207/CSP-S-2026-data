#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll d;
ll x[N];
int dist[N],cnt[N];
vector<int> adj[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    for(int i=1;i<=n;i++) cnt[i]=0,dist[i]=-1;
    dist[s]=0;
    cnt[s]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto v:adj[cur])
        {
            if(dist[v]==-1)
            {
                dist[v]=dist[cur]+1;
                cnt[v]=cnt[cur];
                q.push(v);
            }
            else if(dist[v]==dist[cur]+1)
            {
                cnt[v]+=cnt[cur];
            }
        }
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c==13||c==14)
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            int pos=-1;
            for(int i=1;i<=n;i++)
            {
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
                {
                    pos=i;
                    break;
                }
            }
            ll ans=0;
            for(int v=0,u=1;u<=n;u++)
            {
                while(v<n&&x[v+1]-x[u]<=d) v++;
                if(v>=u+2&&u!=pos)
                {
                    int l=upper_bound(x+1,x+n+1,x[v-2]+d)-x,r=upper_bound(x+1,x+n+1,x[v-1]+d)-x-1;
                    l=max(l,v);
                    if(l<=r) ans+=1ll*(r-l+1);
                    //cout<<u<<" "<<l<<" "<<r<<"\n";
                }
            }
            cout<<ans<<"\n";
        }
    }
    else
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            for(int v=0,i=1;i<=n;i++)
            {
                while(v<n&&x[v+1]-x[i]<=d) v++;
                for(int j=i+1;j<=v;j++)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            ll ans=0;
            for(int u=1;u<n;u++)
            {
                bfs(u);
                //(int j=1;j<=n;j++) cout<<cnt[j]<<" ";
                //cout<<"\n";
                for(int v=u+1;v<=n;v++) if(cnt[v]==2) ans++;
            }
            cout<<ans<<"\n";
            for(int i=1;i<=n;i++) adj[i].clear();
        }
    }
    return 0;
}
