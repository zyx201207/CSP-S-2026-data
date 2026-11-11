#include <bits/stdc++.h>

#define LL long long

using namespace std;
const int N = 5e5 + 10;
LL a[N], s[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	LL m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++)
		s[i] = s[i - 1] + a[i];
	int ans = 1;
	for(int i = 1;i <= n;i ++){
		int l = 1, r = i - 1, res = 1;
		while(l <= r){
			int mid = (l + r) / 2;
			LL cost = a[i] * (i - mid + 1) - (s[i] - s[mid - 1]);
			if(cost > m) l = mid + 1;
			else r = mid - 1, res = max(res, i - mid + 1);
		}
		ans = max(ans, res);
	}
	cout << ans << "\n";
	return 0;
}
