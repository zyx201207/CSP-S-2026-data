#include <bits/stdc++.h>

using namespace std;

long long n, m, ans = 1;
long long a[500010], b[500010];

int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
		
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}	
	
	for (int i = 1; i <= n; i ++ )
	{
		long long dy;
		long long num = 1;
		
		for (int j = i + 1; j <= n; j ++ )
		{
			dy = b[j] - a[i - 1];
			
			int ma = a[j] * (num + 1);
			
//			cout << i << ' ' << j <<' '<< dy << ' ' <<ma<<endl;
			
			if (abs (ma - dy) > m)
			{
				break;
			}
			else
			{
				num ++ ;
				ans = max (ans, num);
//				cout<<"num"<<num<< ' '<<endl;
			}
		}
	}
	
	cout << ans;
	
	return 0;
} 
