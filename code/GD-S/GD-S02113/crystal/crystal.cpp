#include <bits/stdc++.h>
using namespace std;

long long a[500005],sum[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	int l = 1,r = n;
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
		l = 1,r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(i - l + 1,ans);
	}
	cout << ans;
	return 0;
 } 
