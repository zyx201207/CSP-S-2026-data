#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll c,n,m,q,w[N],d,ans;
vector<ll> dp;
ll i,j;
bool f[N];
vector<ll> g[N],a[520],t[520];
void bfs(ll nm)
{
	queue<ll> q;
	q.push(nm);
	ll i;
	while(!q.empty())
	{
		ll tt=q.front();
		q.pop();
		for(auto u:g[tt])
		{
			for(i=0;i<a[u].size();i++)
			{
				ll ax=a[u][i],tx=t[u][i];
				if(ax==tt)
				{
					continue;
				}
				if(!f[ax]&&dp[tt]+tx<=dp[ax])
				{
					dp[ax]=dp[tt]+tx;
					f[ax]=true;
					q.push(ax);
//					cout<<ax<<" "<<dp[ax]<<"\n";
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(j=1;j<=k;j++)
		{
			ll t1,t2;
			scanf("%lld%lld",&t1,&t2);
			a[i].push_back(t1);
			t[i].push_back(t2);
			g[t1].push_back(i);
		}
	}
	while(q--)
	{
		dp=vector<ll>(N,INT_MAX);
		ll u,v;
		scanf("%lld%lld",&u,&v);
		dp[u]=0;
		bfs(u);
		cout<<dp[v]+w[u]+w[v]<<"\n";
//		cout<<"      \n";
		memset(f,false,sizeof(f));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
