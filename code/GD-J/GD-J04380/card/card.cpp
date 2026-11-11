#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N];
int dp[N];
int used[N],ans[N],sum[N];
bool vis[N];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n/2; i++)
	{
		int j = n-i+1;
		swap(a[i],a[j]);
	}
	
	for(int i=1; i<=n; i++)
	{
		
		if(used[a[i]] == 0)
		{
			dp[i] = i-1;
			used[a[i]] = i;
		}
		else
		{
			dp[i] = used[a[i]];
			used[a[i]] = i;
		}
//		cout<<dp[i]<<' ';
	}
	
	for(int i=1; i<=n; i++)
	{
		sum[i] = 1;
		vis[i] = false;
	}
	
	for(int i=n;i>=1;i--)
	{
		sum[dp[i]] += sum[i];
//		cout<<sum[i]<<' ';
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[a[i]] == true) continue;
		vis[a[i]] = true;
		ans[a[i]] = sum[i];
	}
	
	for(int i=1; i<m; i++) cout<<ans[i]<<' ';
	cout<<ans[m];
	return 0;
}
