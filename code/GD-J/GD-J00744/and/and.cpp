#include <bits/stdc++.h>
using namespace std;
long long  a[2000005];
long long n,m;
long long  maxn = 0;
bool f[100005];
long long q[1000005];
long long b[1000005];
void dfs(int step,long long  sum)
{
	if (step== m)
	{
		maxn = max(maxn,sum);
		return ;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if (step==0)
		{
			if (f[i] == 0)
			{
				f[i] = 1;
				dfs(step+1,a[i]);
				f[i] = 0; 
			}
		}
		else if (f[i] == 0)
		{
			f[i] = 1;
			long long l = sum&a[i];
			dfs(step+1,l);
			f[i] = 0; 
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20)
	{
		dfs(0,0);
		cout << maxn;
		return 0;
	}
	if (m==1)
	{
		for (int i = 1; i <= n; i++) maxn = max(maxn,a[i]);
		cout << maxn;
		return 0;
	}
	if (m==n)
	{
		maxn = a[1];
		for (int i = 2; i <= n; i++) maxn = maxn&a[i];
		cout << maxn;
		return 0;
	}
	if (m== 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ( i == j)continue;
				long long l = a[i];
				l = l & a[j];
				maxn = max(maxn,l);
			}
		}
		cout << maxn;
		return 0;
	}
	if (m ==n-1)
	{
		q[1] = a[1];
		b[n] = a[n];
		for (int i = 2; i <= n; i++)
		{
			q[i] = q[i-1] & a[i];
		}
		for (int i = n-1; i >=1; i--)
		{
			b[i] = b[i+1] & a[i];
		}
		for(int i = 2;i < n; i++)
		{
			long long l = q[i-1];
			long long r = b[i+1];
			maxn = max(maxn,l&r);
		}
		maxn = max(maxn,q[n-1]);
		maxn = max(maxn,b[2]);
		cout << maxn;
		return 0;
	}
	return 0;
 } 
