#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
unsigned long long n , a[N] , con , ans;
char c[N];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> c[i];
		con += a[i];
	}
	int ccon = con;
	con /= 2;
	for(int i = 1 ; i <= n ; i++)
	{
		if(con >= a[i])
		{
			con -= a[i];
		}
		else if(con == 0 && ccon % 2 != 0)
		{
			a[i]--;
			break;
		}
		else if(con == 0 && ccon % 2 == 0)
		{
			break;
		}
		else if(con != 0 && ccon % 2 == 0)
		{
			a[i] -= (a[i] - con) * 2;
			break;
		}
		else if(con != 0 && ccon % 2 != 0)
		{
			a[i] = 1 - a[i] + 2 * con;
			break;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int cnt = n;
		while(a[i] != 0)
		{
			if(c[cnt] != c[i] && a[cnt] <= a[i])
			{
				a[i] -= a[cnt];
				n--;
				ans += a[cnt];
				cnt--;
			}
			else if(c[cnt] == c[i] && a[i] >= a[cnt])
			{
				a[i] -= a[cnt];
				n--;
				cnt--;
			}
			else if(c[cnt] == c[i] && a[i] < a[cnt])
			{
				a[cnt] -= a[i];
				break;
			}
			else if(c[cnt] != c[i] && a[cnt] > a[i])
			{
				a[cnt] -= a[i];
				ans += a[i];
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

