#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 100;
int n;
ll d, a[MAXN], st[MAXN], ed[MAXN];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		st[i] = i + 1;
		ed[i] = lower_bound(a + 1, a + 1 + n, a[i] + d + 1) - a - 1;
		if(ed[i] - st[i] + 1 == 2 && ed[i] != n) ans++;
//		cout << st[i] << ' ' << ed[i] << '\n';
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int _;
	cin >> _ >> _;
	while(_--){
		solve();
	}
	return 0;
}
