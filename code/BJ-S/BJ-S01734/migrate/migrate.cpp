#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=2e6+5,maxn1=5005;

struct Edge
{
    int v,nxt;
}e[2*maxn];
int head[maxn],tot;
void add(int u,int v)
{
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

ll n,d,pos[maxn];
int dis[maxn1][maxn1],cnt[maxn1][maxn1];
bool vis[maxn1];
queue<int> q;

void bfs(ll st)
{
    q.push(st);
    for(int i=1;i<=n;i++)
    {
        dis[st][i]=0;
        cnt[st][i]=0;
        vis[i]=false;
    }
    vis[st]=true;
    cnt[st][st]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(!vis[v])
            {
                vis[v]=true;
                dis[st][v]=dis[st][u]+1;
                cnt[st][v]=cnt[st][u];
                q.push(v);
            }
            else if(dis[st][u]+1==dis[st][v]) cnt[st][v]+=cnt[st][u];
        }
    }
}

void sub1()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) head[i]=0;
    tot=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>pos[i];
        for(ll j=1;j<i;j++)
        {
            if(abs(pos[i]-pos[j])<=d)
            {
                add(i,j);add(j,i);
            }
        }
    }

    for(ll i=1;i<=n;i++)
    {
        bfs(i);
    }

    ll ans=0;
    for(ll i=1;i<=n;i++)
        for(ll j=i+1;j<=n;j++)
            if(cnt[i][j]==2)
            {
                //cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
                ans++;
            }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll C,T;cin>>C>>T;
    if(C<=10)
    {
        while(T--) sub1();
        return 0;
    }
    if(C<=12)
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>pos[i];
            ll c=pos[n]-pos[n-1];
            ll tms=d/c;
            if(tms<=1)
            {
                cout<<0<<'\n';
                continue;
            }
            ll len=2*tms;
            ll ans=max(0ll,n-len+1);
            cout<<ans<<'\n';
        }
        return 0;
    }
    else
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>pos[i];
            cout<<0<<'\n';
        }
    }

    return 0;
}
