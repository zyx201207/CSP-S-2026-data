#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;

int n,m;
long long a[MAXN];

long long dp[MAXN][MAXN]; 

long long tl1 = -1,tl2;

void solve_tl3()
{
	long long ans = -1;
	for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++)
	{
		ans = max(ans,(long long)(a[i]&a[j]));
	} 
	cout << ans;
	return;
}

bool vis[MAXN];
long long ret_tl4 = -1;
void solve_tl4(int cnt)
{
	if(cnt == m)
	{
		long long num;
		bool flag = false;
		for(int i = 1;i <= n;i++)
		{
			if(!vis[i]) continue;
			if(!flag){num = a[i];flag = true;}
			else num = (num & a[i]);
		}
		ret_tl4 = max(ret_tl4,num);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) continue;
		vis[i] = true;
		solve_tl4(cnt+1);
		vis[i] = false;
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		dp[i][1] = a[i];
		
		tl1 = max(tl1,a[i]);
		
		if(i == 1) tl2 = a[i];
		else tl2 = (tl2 & a[i]);
	}
	
	if(m == 1){cout << tl1;return 0;}
	if(m == n){cout << tl2;return 0;}
	if(m == 2){solve_tl3();return 0;}
	if(n <= 11){solve_tl4(0);cout << ret_tl4;return 0;}
	
	for(int i = 1;i <= n;i++) for(int j = 1;j <= i;j++)
	{
		dp[i][j] = max((dp[i-1][j-1] & a[i]),dp[i][j]); 
		dp[i][j] = max(dp[i-1][j],dp[i][j]);
	}
	
	cout << dp[n][m];
	return 0;
}
