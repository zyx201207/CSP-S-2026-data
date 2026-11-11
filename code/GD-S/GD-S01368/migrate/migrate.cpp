#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

const ll N=5010;
vector<ll> e[N];
ll C,T,n,m,ans,a[N],dis[N][N];

void init(){for(ll i=1;i<N;i++) for(ll j=1;j<N;j++) dis[i][j]=1e18;}

void dij(ll s)
{
	queue<ll> q;
	q.push(s);
	dis[s][s]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		
		for(auto v:e[u])
		{
			if(dis[s][u]+1<dis[s][v]) dis[s][v]=dis[s][u]+1;
			q.push(v);
		}
	}
	return;
}

ll bfs(ll i,ll j)
{
	ll cnt=0;
	
	queue<pll> q;
	q.push({i,0});
	while(!q.empty())
	{
		ll u=q.front().first,num=q.front().second;
		q.pop();
		
		if(u==j && num==dis[i][j]) cnt++;
		
		if(u==j || num>=dis[i][j]) continue;
		
		for(auto v:e[u]) q.push({v,num+1});
	}
	return cnt;
}

void solve()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	if(C==11 || C==12)
	{
		ans=0;
		ll num=a[1]+m;
		num=upper_bound(a+1,a+n+1,num)-a-2;
		for(ll i=1;i<=n;i++)
		{
			ll l=i+3,r=i+2*num-1;
			if(r<=n) ans++;
			if(l<=n) ans++;
		}
		cout<<ans<<endl;
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			ll l=a[i]-m,r=a[i]+m;
			r=upper_bound(a+1,a+n+1,r)-a-1;
			for(ll j=i+1;j<=r;j++) e[i].push_back(j);
		}
		
		init();
		for(ll i=1;i<=n;i++) dij(i);
		for(ll i=1;i<=n-3;i++) for(ll j=i+3;j<=n;j++) if(bfs(i,j)==2) ans++;
		cout<<ans<<endl;
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;while(T--) solve();
	return 0;
}
