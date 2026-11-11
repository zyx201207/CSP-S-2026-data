#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, ans = 1;
long long m, a[N], pre[N];

inline bool check(int pos){
	int cnt = 0; long long rest = m;
	for(int i = pos - 1; i >= 1; i--){
		if(rest >= a[pos] - a[i]) rest -= a[pos] - a[i], cnt++;
		else break;
	}
	ans = max(ans, cnt + 1);
	return cnt == pos - 1;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) r = mid - 1, ans = max(ans, i - mid + 1);
			else l = mid + 1;
		}
	}
	
	/*int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}*/
	cout << ans << '\n';
	return 0;
}
