#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int l = 1,sum = 0,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		while(l < i && (i - l) * a[i] - sum > m)
		{
			sum -= a[l];
			l++;
		}
		ans = max(ans,i - l + 1);
		sum += a[i];
	}
	cout << ans;
	return 0;
}
