#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
ll n, d;

struct code
{
	ll left, right, cnt;
	ll id, sum, va;
	bool pd;
} a[N];

bool cmp(const code &a, const code &b)
{
	return a.sum < b.sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t--)
	{
		ll l, r, ans(0);
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].sum;
			a[i].va = 1;
		}
		sort(a+1, a+n+1, cmp);
		for (int i = 1; i <= n; i++)
		{
			a[i].left = i;
			a[i].right = i;
			a[i].id = i;
		}
			
		for (int i = 1; i < n; i++)
		{
			if (a[i+1].sum - a[i].sum == d)
			{
				a[i+1].va += a[i].va;
				a[i].va = 0;
			}
			else
			{
				l = i;
				break;
			}
		}
		
		for (int i = n; i > 1; i--)
		{
			if (a[i].sum - a[i-1].sum == d)
			{
				a[i-1].va += a[i].va;
				a[i].va = 0;
			}
			else
			{
				r = i;
				break;
			}
		}
		
		for (int i = l; i <= r; i++)
		{
			for (int j = i; j <= i + d; j++)
			{
				if (a[j].sum - a[i].sum <= d)
				{
					if (!a[i].pd || j == i + 1)
					{
						a[i].left = a[j].id;
						a[i].pd = true;
					}
					if (j <= n)
						a[i].right = a[j].id;
				}
			}
			a[i].cnt = a[i].right - a[i].left + 1;
		}
		
			
		for (int i = l; i <= r; i++)
		{
			
			for (int j = i + 3; j <= r; j++)
			{
				ll o(0);
				if (a[i].right == j)
					continue;
				for (int k = a[i].left; k <= a[i].right; k++)
				{
					if (a[k].left <= j && j <= a[k].right)
						o++;
				}
				if (o == 2)
					ans += a[i].va * a[j].va;
			}
		}
		
//		cout << l << ' ' << r << '\n';
//		for (int i = l; i <= r; i++)
//			cout << a[i].va << ' ';
//		cout << '\n';
//		for (int i = l; i <= r; i++)
//			cout << a[i].left << ' ' << a[i].right << ' ';
//		cout << '\n';
//		for (int i = l; i <= r; i++)
//			cout << a[i].cnt << ' ';
//		cout << '\n';
		cout << ans << '\n';
	}
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3 
-2 -1 0 1 2 

6 2 
-4 -3 -2 -1 3 6


9

10 3
-1000000000000000000  
-999999999999999997 
-999999999999999994 
-999999999999999993 
-999999999999999992 
-999999999999999991 
-999999999999999990 
-999999999999999989 
-999999999999999986 
-999999999999999983


6 1200000000000000000
-1000000000000000000 
-600000000000000000 
-200000000000000000 
200000000000000000 
600000000000000000 
1000000000000000000


0 1
6 2
-4 -3 -2 -1 3 6
*/
