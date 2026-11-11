#include<bits/stdc++.h>
using namespace std;
long long n , m , k , ans , a[500010] , l , vis[500010] , s = 1;
long long b[500010];
long long dp[200010];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	scanf("%lldlld" , &n , &m);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(vis[j] == 0)
			{
				l++;
				b[l] = a[j];
			}
			if(b[l] == m)
			{
				for(int k = 1; k <= l - 1; k++)
					if(b[k] == m) 
					{
						for(int p = k; p <= j - 1; p++) 
						{
							vis[p] = 1;
							l--;
							b[p] = b[p + j - 1 - k + 1];
						}
					}
			}
		}
		for(int j = 1; j <= l; j++) 
		{
			if(b[j] == s) ans++;
		}
		if(ans != 0)
		{
			cout << ans << " ";
		}
		ans = 0;
		s++;
	}
	return 0;
} 
