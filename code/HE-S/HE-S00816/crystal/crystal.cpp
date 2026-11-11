#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n,ans;
ll a[N],m;
ll sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++ i) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++ i) sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;++ i)
	{
		int L = 0,R = i + 1;
		while(L + 1 != R)
		{
			int mid = L + R >> 1;
			if((__int128)a[i] * mid - sum[mid - 1] >= (__int128)a[i] * (i + 1) - sum[i] - m) R = mid;
			else L = mid;
		}
		ans = max(ans,i - R + 1);
	}
	cout << ans << "\n";
	return 0;
}
