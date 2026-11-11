#include <bits/stdc++.h>
using namespace std;

struct p
{
	long long n,x;
};

long long n,m;
long long a[(long long)5e5 + 5];
p b[(long long)1e5 + 5];
long long maxn = 0;
long long cnt = 0;
long long maxnnum = -1e12;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long flag_1 = 1;
	long long flag_2 = 1;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		maxnnum = max(maxnnum,abs(a[i]));
	}
	sort(a + 1,a + n + 1);
	for(long long i = 1;i <= n;i++)
	{
		if (a[i] == a[i - 1])
		{
			cnt++;
		}
		else
		{
			maxn = max(maxn,cnt);
			cnt = 1;
		}
		if (a[i] != i)
		{
			flag_1 = 0;
		} 
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
		{
			flag_2 = 0;
		}
	}
	maxn = max(maxn,cnt);
	if (m == 0)
	{
		cout << maxn << endl;
		return 0;
	}
	if (flag_1)
	{
		m = m * 2;
		long long l = 1;
		long long r = 5e5;
		long long mid;
		long long ans = 0;
		while(l <= r)
		{
//			printf("%lld %lld %lld %lld %lld\n",l,r,mid,m,mid * (mid + 1));
			mid = l + (r - l) / 2;
			if (mid * (mid + 1) <= m)
			{
				ans = max(ans,mid);
				l = mid + 1; 
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << ans + 1 << endl;
		return 0;
	}
	if (flag_2)
	{
		long long k = abs(a[2] - a[1]);
		m = m * 2;
 		long long l = 1;
		long long r = 5e5;
		long long mid;
		long long ans = 0;
		while(l <= r)
		{
			mid = l + (r - l) / 2;
//			printf("%lld %lld %lld %lld %lld\n",l,r,mid,m,(k + mid * k) * mid);
			if ((k + mid * k) * mid <= m)
			{
				ans = max(ans,mid);
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << ans + 1 << endl;
		return 0;
	}
	if (n <= 16)
	{
		long long num = 0;
		maxn = 0;
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = i + 1;j <= n;j++)
			{
				num = 0;
				for(long long x = i;x <= j;x++)
				{
					num += abs(a[x] - a[j]);
				}
				if (num <= m)
				{
					maxn = max(maxn,j - i + 1);
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (n <= 5e5 && maxnnum <= 1e5)
	{
		cnt = 0;
		maxn = 0;
		b[++cnt].n = a[1];
		b[cnt].x = 1;
		for(long long i = 2;i <= n;i++)
		{
			if (b[cnt].n != a[i])
			{
				b[++cnt].n = a[i];
				b[cnt].x = 1;
			}
			else
			{
				b[cnt].x++;
			}
		}
		//
//		for(long long i = 1;i <= cnt;i++)
//		{
//			printf("%d %d\n",b[i].n,b[i].x);
//		}
		long long num = 0;
		long long ans = 0;
		for(long long i = 1;i <= cnt;i++)
		{
			num = 0;
			ans = b[i].x;
			for(long long j = i - 1;j >= 1 && num <= m;j--)
			{
//				printf("%d %d %d %d\n",i,j,ans,num);
				if (b[j].x <= (m - num) / abs(b[i].n - b[j].n))
				{
					ans += b[j].x;
				}
				else
				{
					ans += (m - num) / abs(b[i].n - b[j].n);
				}
				num += b[j].x * abs(b[i].n - b[j].n);
			}
			maxn = max(maxn,ans);
		}
		cout << maxn << endl;
		return 0;
	}
	return 0;
}

/*
5 5
1 2 4 8 9
*/


