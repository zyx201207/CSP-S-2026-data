#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e2 + 5;
const ll M = 5e5 + 5;
const ll D = 25;
ll c,n,m,d,q,dp[N][N];
ll w[M],a[M][D],t[M][D];
vector<ll>s[M];
void add(ll x)
{
	ll sz=s[x].size();
	for(int i=0;i<sz;i++)
	{
		for(int j=i+1;j<sz;j++)
		{
			dp[s[x][i]][s[x][j]]=dp[s[x][j]][s[x][i]]=min(dp[s[x][i]][s[x][j]],t[x][s[x][i]]+t[x][s[x][j]]);
		}
	}
	return;
}
ll solve(ll x,ll y)
{
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(auto &u:s[x])
	{
		for(auto &v:s[y])
		{
			ans=min(ans,dp[u][v]+w[x]+w[y]+t[x][u]+t[y][v]);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
			s[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++) add(i);
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==k||i==j||k==j) continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
//		}
//	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;	
}
/*
绝对是Floyd!!! 
绝对是Floyd!!! 
绝对是Floyd!!! 
绝对是Floyd!!! 
绝对是Floyd!!! 
*/
