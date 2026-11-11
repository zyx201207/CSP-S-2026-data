#include <bits/stdc++.h>
using namespace std;

struct p
{
	int n,x;
};

int n,m,k;
int a[(int)2e5 + 5];
p b[(int)2e5 + 5];
int v[(int)2e5 + 5];

int f(int x)
{
	x++;
	if (pow(2,log2(x)) == x)
	{
		return 1;
	}
	return 0;
}

int dfs(int x,int step)
{
	if(step == m + 1)
	{
		return x;
	}
	int maxn = 0;
	for(int i = 1;i <= n;i++)
	{
		if (v[i])
		{
			continue;
		}
		v[i] = 1;
		maxn = max(maxn,dfs(x & a[i],step + 1));
		v[i] = 0;
	}
	return maxn;
}

int cmp(int x,int y)
{
	return x > y;
}

int check(int x)
{
	int cnt = 0;
	for(int i = 1;i <= k;i++)
	{
		if (b[i].n < x)
		{
			break;
		}
		if (b[i].n & x == x || x == b[i].n)
		{
			cnt += b[i].x;
		}
//		printf("%d %d %d %d\n",i,b[i].n,x,b[i].n & x);
	}
//	cout << cnt << endl;
	if (cnt >= m)
	{
		return 1; 
	}
	else
	{
		return 0;
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int flag_A = 1;
	int flag_0 = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			flag_0++;
		}
		if (f(a[i]) == 0)
		{
			flag_A = 0;
		}
	}
	int ans = 0;
	if (n <= 20 && m <= n)//#1-5
	{
		for(int i = 1;i <= n;i++)
		{
			v[i] = 1;
			ans = max(ans,dfs(a[i],2));
			v[i] = 0;
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 2000 && m == 1)//#6
	{
		for(int i = 1;i <= n;i++)
		{
			ans = max(ans,a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 2000 && m == n)//#7
	{
		ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 2000 && m == 2)//#8-10
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (flag_A)//#13_A
	{
		sort(a + 1,a + n + 1,cmp);
		ans = a[1];
		for(int i = 2;i <= m;i++)
		{
			ans = ans & a[i]; 
		}
		cout << ans << endl;
		return 0;
	}
	if (m == 1)// m = 1
	{
		for(int i = 1;i <= n;i++)
		{
			ans = max(ans,a[i]);
		} 
		cout << ans << endl;
	}
	k = 0;
	sort(a + 1,a + n + 1,cmp);
	b[k].n = -1;
	for(int i = 1;i <= n;i++)
	{
		if (a[i] != b[k].n)
		{
			b[++k].n = a[i];
			b[k].x = 1;
		}
		else
		{
			b[k].x++;
		}
//		printf("%d %d %d %d %d\n",i,a[i],k,b[k].n,b[k].x);
	}
	int l = 1;
	int r = k;
	int mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
//		printf("#%d %d %d\n",l,r,mid);
		if (check(b[mid].n))
		{
			ans = b[mid].n;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
} 

/*
4 2
3 15 12 12

*/
