#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const long long N = 2e5+5;

long long n,mm,ans,a[N],dp[N][2];

void dfs(long long now,long long m,long long sum)
{
	//cout << now << ' ' << m << ' ' << sum << endl;
	if(m == mm)
	{
		ans = max(ans,sum);
		return;
	}
	if(now > n)return;
	dfs(now + 1,m+1,sum & a[now+1]);
	dfs(now+1,m,sum); 
	return;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> mm;
	for(long long i = 1;i<=n;i++)cin >> a[i];
	//1. n<20
	
	if(n <= 20)
	{
		for(long long i = 1;i<=n;i++)
		{
			dfs(i,1,a[i]);
		}
	cout << ans << endl;
	return 0;
	}
	if(mm == 1)
	{
		long long maxn = -2e17;
		for(long long i = 1;i<=n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(mm == 2)
	{
		long long maxn = -2e17;
		for(long long i = 1;i<=n;i++)
		{
			for(long long j = 1;j<i;j++)
			{
				maxn = max(maxn,a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	} 
	if(mm == n-1)
	{
		
		return 0;
	}
	return 0;
}
//50pts
