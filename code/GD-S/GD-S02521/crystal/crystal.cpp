#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long n , m , a[N] , sum[N] , ans;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i]; 
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1 , a + n + 1); 
	for(register long long j = 1 ; j <= m ; j++)
	{
		for(register long long i = n ; i >= 1 ; i--)
		{
			for(register long long k = i - 1 ; k >= 0 ; k--)
			{		
				long long cnt = sum[i] - sum[k] + j;
				if(cnt % (i - k) == 0 && a[i] <= cnt / (i - k))
				{
					ans = max(ans , i - k); 
				}
			}
		}
	}
	cout << ans;
	return 0;
}
