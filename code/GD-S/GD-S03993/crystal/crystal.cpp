#include <bits/stdc++.h>
using namespace std;

const long long N = 500055;

long long n,m,a[N],sum[N],ans = 1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	
	for(long long i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	
	for(long long i = 1;i <= n;i++)
	{
		while(i - ans > 0 && (ans + 1) * a[i] - (sum[i] - sum[i - ans - 1]) <= m) ans++;
	}
	
	cout << ans;
	return 0;
}
