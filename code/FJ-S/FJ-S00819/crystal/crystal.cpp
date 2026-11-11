#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N],sum[N],m,n,ans;
bool check(long long x)
{
	for (long long i = x;i <= n;i++)
		if (a[i] * x - (sum[i] - sum[i - x]) <= m)
		    return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	    cin >> a[i];
	sort(a + 1,a + n + 1);
	for (long long i = 1;i <= n;i++)
	    sum[i] = sum[i - 1] + a[i];
	long long l = 1,r = n;
	while (l <= r){
		long long mid = (l + r) / 2;
		if (check(mid)){
			ans = max(ans,mid);
		    l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}
