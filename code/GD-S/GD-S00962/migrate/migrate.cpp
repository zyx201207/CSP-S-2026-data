#include <iostream>
using std::cin;
using std::cout;

const long long inf = 1e18;

long long c, t;

long long a[2000005];

long long left[2000005], right[2000005];

long long l_ok[2000005], r_ok[2000005];


int main()
{
	freopen("migrate3.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while(t--)
	{
		long long n, d;
		
		cin >> n >> d;
		
		for(long long i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(a[j] - a[i] > d)
				{
					l_ok[i] = j - i - 1;
					
					goto end1;
				}
			}
			
			l_ok[i] = n - i;
			
			end1:;
		}

		for(int i = 1; i <= n; i++)
		{
			for(int j = i - 1; j >= 1; j--)
			{
				if(a[i] - a[j] > d)
				{
					r_ok[i] = i - j - 1;
					
					goto end2;
				}
			}
			
			r_ok[i] = i - 1;
			
			end2:;
		}
		
		left[1] = left[n] = right[1] = right[n] = 1;
		
		a[0] = -inf;
		a[n + 1] = inf;
		
		for(long long i = 2; i < n; i++)
		{
			if(a[i] - a[i - 1] <= d and a[i] - a[i - 2] > d and a[i + 1] - a[i - 1] > d)
			{
				left[i] = left[i - 1] + 1;
			}
			else
			{
				left[i] = 1;
			}
		}
		
		for(long long i = n; i >= 2; i--)
		{
			if(a[i + 1] - a[i] <= d and a[i + 1] - a[i - 1] > d and a[i + 2] - a[i] > d)
			{
				right[i] = right[i + 1] + 1;
			}
			else
			{
				right[i] = 1;
			}
		}
		/*
		for(int i = 1; i <= n; i++)
		{
			cout << left[i] << " ";
		}
		
		cout << '\n';
		
		for(int i = 1; i <= n; i++)
		{
			cout << right[i] << " ";
		}
		
		cout << '\n';*/
		
		long long ans = 0;
		
		for(long long l = 1; l + 3 <= n; l++)
		{
			for(long long r = l + std::max(l_ok[l] + 1, 3LL); r <= n; r++)
			{
				int type = 0;
				
				for(long long mid = l + 1; mid < r; mid++)
				{
					if(a[mid] - a[l] < d and a[r] - a[mid] < d)
					{
						type++;
					}
				}
				
				if(type == 2)
				{
					ans += left[l] * right[r];
				}
			}
		}
		
		cout << ans << '\n';
	}
}
/*
0 3
8 3
1 3 4 6 9 11 12 14
6 3
1 3 4 5 6 8
6 3
0 1 2 3 4 7
*/











