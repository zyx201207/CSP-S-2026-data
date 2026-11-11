#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll a[N];
ll pa[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) pa[i] = pa[i-1]+a[i];
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[n]-a[i];
	if (sum <= m)
	{
		cout << n;
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = i;
		while (l+1 < r)
		{
			int mid = (l+r)>>1;
			if (a[i]*(i-mid)-pa[i-1]+pa[mid-1] <= m) r = mid;
			else l = mid;
		}
		ans = max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}

