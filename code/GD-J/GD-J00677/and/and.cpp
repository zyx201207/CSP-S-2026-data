#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m;
int a[N];
int dp[2010][2010];
int cnt[32];
int fl1 = 1,fl2 = 1;
int ANS;
void dfs(int now,int c,int l)
{
	if(now > n) return;
	if(c == m)
	{
		ANS = max(ANS,l);
		return;
	}
	if(l == 0)
	{
		dfs(now+1,c+1,a[now]);
		dfs(now+1,c,l);
	}
	else
	{
		dfs(now+1,c+1,l&a[now]);
		dfs(now+1,c,l);
	}
}
void solve1()
{
	if(m == 1)
	{
		int Max = 0;
		for(int i=1;i<=n;i++) Max = max(Max,a[i]);
		cout << Max;
	}
	else if(m == 2)
	{
		int Max = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				Max = max(Max,a[i]&a[j]);
			}
		}
		cout << Max;
	}
	else if(m == n)
	{
		int Max = a[1];
		for(int i=2;i<=n;i++) Max = Max & a[i];
		cout << Max;
	}
	else
	{
		dfs(1,0,0);
		cout << ANS;
	}
}
void solve2()
{
	int sum = a[1],ans = 0;
	for(int i=2;i<=n;i++) sum = sum & a[i];
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=30;k++)
		{
			if(!((a[i] >> k) & 1)) cnt[k]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int p = sum;
		for(int k=0;k<=30;k++)
		{
			if(cnt[k] == 1 && !((a[i] >> k) & 1)) p += (1<<k);
		}
		ans = max(ans,p);
	}
	cout << ans;
}
void solve3()
{
	sort(a+1,a+1+n);
	cout << a[n-m+1];
}
void solve4()
{
	int ans = a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		ans &= a[i];
	} 
	cout << ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] != (1<<i)-1) fl1 = 0;
		if(a[i] != (i-1)) fl2 = 0;
	}
	if(m == n-1) solve2();
	else if(fl1) solve3();
	else if(fl2) solve4();
	else if(n <= 2000) solve1();
	return 0;
}
