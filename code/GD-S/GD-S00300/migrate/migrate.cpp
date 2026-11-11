#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=300;
ll c,T,n,d,x[N];
ll w[N][N],dis[N][N];
ll cnt,head[N];
struct Edge
{
	ll to,next;
}edge[N*N];
void add(ll u,ll v)
{
	edge[++cnt]={v,head[u]};head[u]=cnt;
	edge[++cnt]={u,head[v]};head[v]=cnt;
	w[u][v]=w[v][u]=1;
	dis[u][v]=dis[v][u]=1;
}
void solve()
{
	cnt=0;
	memset(w,0x3f,sizeof(w));
	memset(dis,0x3f,sizeof(dis));
	memset(head,0,sizeof(head));	
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>x[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(abs(x[i]-x[j])<=d) add(i,j);
		}	
	}
	for(ll i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{			
			ll sum=0;
			for(ll k=1;k<=n;k++)
			{
				if(k==i||k==j) continue;
				if(dis[i][k]+dis[k][j]==dis[i][j]) sum++;
			}
			if(sum==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

