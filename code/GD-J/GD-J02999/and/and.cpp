#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005],maxn,b[200005];

long long ad(long long x,long long y)
{
	int w[50] = {},z[50] = {},l[50] = {},len_w,len_z;
	int cnt = 0;
	while (x != 0)
	{
		w[cnt] = x % 2;
		x /= 2;
		cnt ++;
	}
	len_w = cnt;
	cnt  = 0;
	while (y != 0)
	{
		z[cnt] = y % 2;
		y /= 2;
		cnt ++;
	}
	len_z = cnt;
	for (int i = 0;i < max(len_w,len_z);i ++)
	{
		if (w[i] == z[i])
		{
			if (w[i] == 1)
			{
				l[i] = 1;
			}
		}
		else l[i] = 0;
	}
	long long ans = 0;
	for (int i = max(len_w,len_z) - 1;i >= 0;i --)
	{
		if (l[i] == 1) ans += pow(2,i);
	}
	return ans;
}

void dfs(long long x,long long y)
{
	if (y > m)
	{
		long long num = ad(b[1],b[2]);
		for (int i = 3;i <= m;i ++)
		{
			num = ad(num,b[i]);
		}
		maxn = max(maxn,num);
		return ;
	}
	for (int i = x;i <= n;i ++)
	{
		b[y] = a[i];
		dfs(i + 1,y + 1);
		b[y] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	dfs(1,1);
	cout << maxn;
	
	return 0;
} 
