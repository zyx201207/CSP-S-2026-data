#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define M 505
using namespace std;
struct stu
{
    ll pp,t;
    bool operator<(const stu &p)const{
        return t>p.t;
    }
};
vector<stu> b[M],g[N];
vector<stu> tree[N];
ll a[M],f[N][M],flag[N],dis[N];
priority_queue<stu> q;
ll c,n,m,d,T;
void dij(int s)
{
    while(!q.empty())
        q.pop();
    for(ll i=1;i<=n;i++)
        dis[i]=-1;
    dis[s]=0;
    while(!q.empty())
    {
        stu u=q.top();
        q.pop();
        if(u.t>dis[u.pp])
        {
            continue;
        }
        for(auto i:g[u.pp])
        {
            int v=i.pp,w=i.t;
            if((dis[v]==-1)||(dis[v]>dis[u.pp]+w))
            {
                dis[v]=dis[u.pp]+w;
                q.push((stu){v,dis[v]});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        f[s][i]=dis[i];
    }
}
int main()
{
	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>c>>n>>m>>d>>T;
	for(ll i=1;i<=m;i++)
		cin>>a[i];
    for(ll i=1,k;i<=n;i++)
    {
        cin>>k;
        for(ll j=1,x,y;j<=k;j++)
        {
			cin>>x>>y;
            tree[i].push_back((stu){x,y});
            b[x].push_back((stu){i,y});
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
            flag[j]=-1;
        flag[i]=0;
        for(auto u:tree[i])
        {
            for(auto v:b[u.pp])
            {
                if(v.pp!=i)
                {
                    if(flag[v.pp]==-1)
                    {
                        flag[v.pp]=u.t+v.t;
                    }
                    else
                    {
                        flag[v.pp]=min(flag[v.pp],u.t+v.t);
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            if((j!=i)&&flag[j]!=-1)
            {
                g[i].push_back((stu){j,flag[j]});
            }
        }
        
    }
    for(ll i=1;i<=n;i++)
    {
        dij(i);
    }
    while(T--)
    {
        ll begin,end;
        cin>>begin>>end;
        ll ans=-1;
        for(auto u:b[begin])
        {
            for(auto v:b[end])
            {
                if(ans==-1)
                {
                    ans=f[u.pp][v.pp]+u.t+v.t;
                }
                else
                    ans=min(ans,f[u.pp][v.pp]+u.t+v.t);
            }
        }
        cout<<ans+a[begin]+a[end]<<"\n";
    }
}
