#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n;
ll m, a[N], pre[N];

bool ck(ll mid){
	for(int i = mid; i <= n; i++){
		ll need = pre[i] - pre[i - mid];
		if(mid * a[i] - need <= m){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 1, r = n, ans = 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(ck(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
