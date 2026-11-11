#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[500005], dp[500005], ans;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	//~ for(int i = 1; i <= n; i++) cout << a[i] << endl;
	for(int i = 1; i <= n; i++)
	{
		ll nowm = m, nowres = 1;
		dp[i] = 1;
		int k = i - 1;
		//~ cout << "i = " << i << endl;
		while(k >= 1 && a[k] + nowm >= a[i])
		{
			nowres++;
			nowm -= a[i] - a[k];
			//~ cout << "k = " << k << endl;
			//~ cout << "m = " << nowm << endl;
			//~ cout << "so res = " << nowres << endl;
			k--;
		}
		ans = max(ans, nowres);
	}
	printf("%lld", ans);
	return 0;
}

