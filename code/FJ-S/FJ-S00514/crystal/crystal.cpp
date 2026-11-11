#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n , ans = 1 , cnt;
long long m , a[N] , sum , sem;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cnt = n - 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = n;i >= 2;i--)
	{
		sum = sem;
		sem -= (i-cnt-1)*(a[i]-a[i-1]);
		while(sum + a[i] - a[cnt] <= m && cnt >= 1)
		{
			sem += a[i - 1] - a[cnt];
			sum += a[i] - a[cnt];
			cnt--;
		}
		ans = max(ans , i - cnt);
	}
	cout << ans;
	return 0;
}