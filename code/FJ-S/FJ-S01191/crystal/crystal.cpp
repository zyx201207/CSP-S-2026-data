#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n;
long long m;
int a[MAXN];
long long sum;
int ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++ i)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int r = 1,l = 1;r <= n;++ r)
	{
		sum += a[r];
		long long lf = a[r] * (r - l + 1) - sum - m;
//		cout << sum << '\n';
		while(lf > 0)
		{
			lf -= a[r] - a[l];
			sum -= a[l];
			++ l;
		}
		ans = max(ans,r - l + 1);
	}
	cout << ans;
	return 0;
}

