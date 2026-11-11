#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10,M=305;
ll c,t,n,d,x[N],a[M][M],ans,sum;
bool vis[M];
void dfs(ll v,ll e,ll num,ll mu,vector<ll> b[M])
{
	if(num>mu) return;
	if(e!=v&&num==mu) return;
	if(e==v&&num==mu)
	{
		sum++;
		return;
	}
	for(ll f:b[e])
		if(!vis[f])
		{
			vis[f]=1;
			dfs(v,f,num+1,mu,b);
			vis[f]=0;
		}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;++i) cin>>x[i];
		ans=0;
		vector<ll> b[M];
		memset(a,0x3f,sizeof a);
		for(ll i=1;i<=n;++i) a[i][i]=0;
		for(ll i=1;i<=n;++i)
			for(ll j=i+1;j<=n;++j)
				if(llabs(x[i]-x[j])<=d) a[i][j]=a[j][i]=1,b[i].push_back(j),b[j].push_back(i);
		for(ll k=1;k<=n;++k)
			for(ll i=1;i<=n;++i)
				for(ll j=1;j<=n;++j)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		for(ll i=1;i<=n;++i)
			for(ll j=i+1;j<=n;++j)
			{
				if(a[i][j]==0x3f3f3f3f3f3f3f3f) continue;
				sum=0;
				vis[i]=1;
				dfs(j,i,0,a[i][j],b);
				vis[i]=0;
				if(sum==2) ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
