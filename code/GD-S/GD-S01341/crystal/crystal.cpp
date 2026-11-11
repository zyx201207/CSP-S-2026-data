#include<bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m, A[N], pre[N];

bool check(int l, int r){
	int val = A[r], len = r - l + 1;
	if(val * len - (pre[r] - pre[l - 1]) <= m) return true;
	return false;
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + A[i];
	int res = 0;
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, x = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(mid, i)) r = mid - 1, x = i - mid + 1;
			else l = mid + 1;
		}
		res = max(res, x);
	}
	cout << res << "\n";
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
