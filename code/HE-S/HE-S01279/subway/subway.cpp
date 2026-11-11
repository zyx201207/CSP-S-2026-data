#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
const ll inf64=1e15;
const int inf=1e9;
const int maxn=5e5+5;
ll dis[510][510];
vector<pii> e[maxn];
int w[maxn],c,n,m,d,q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int op;
		pii gh;
		cin>>op;
		for(int j=1;j<=op;j++)
		{
			cin>>gh.fi>>gh.se;
			e[gh.fi].eb(i,gh.se);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) dis[i][j]=inf64;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:e[i])
		{
			for(auto k:e[i])
			{
				if(j.fi==k.fi) continue;
				ll op=1ll*j.se+k.se;
				dis[j.fi][k.fi]=min(dis[j.fi][k.fi],op);
				dis[k.fi][j.fi]=min(dis[k.fi][j.fi],op);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll ans=inf64;
		int l,r;
		cin>>l>>r;
		for(auto j:e[l])
		{
			for(auto k:e[r])
			{
				ans=min(ans,dis[j.fi][k.fi]+j.se+k.se);
			}
		}
		ans+=1ll*w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
