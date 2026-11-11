#include <iostream>
#include <algorithm>
using namespace std;
int n,m,ans;
long long a[500005],s[500005],sum[500005];
bool check(int x)
{
	int minn = sum[x],l = sum[x];
	for(int i = x + 1;i <= n;i++)
	{
		int k = l - (s[i] - s[i - x + 1]) + (a[i] - a[i - 1]) * x;
		minn = min(minn,k);
		l = k;
	}
	return minn <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		s[i] = a[i] - a[1];
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		//cout << s[i] << " " << sum[i] << endl;
	}
	int l = 1,r = n;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid,l = mid;
		else r = mid;
	}
	cout << ans << endl;
	return 0;
}
