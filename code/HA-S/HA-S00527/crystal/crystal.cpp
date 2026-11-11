#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 100;

int n ,m;
int a[maxn];
int pref[maxn];
int sum[maxn];
int ans;

signed main()
{
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 ,a + 1 + n);
	for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
	sum[1] = 0;
	for (int i = 2; i <= n; i++) sum[i] = (i - 1) * a[i] - pref[i - 1];
	for (int i = 1; i <= n; i++) if (sum[i] <= m) ans = i;
	cout << ans << '\n';
	
	return 0;
}
