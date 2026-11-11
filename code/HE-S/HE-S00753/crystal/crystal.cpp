#include <bits/stdc++.h>
#define il inline
#define int long long
using namespace std;
const int N = 5e5+100, inf = 3e18;

int n, m, a[N], ans[N], res;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int rest = m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1, j = 1; i <= n; i++){
		if(i == 1) {
			ans[i] = 1;
			continue;
		}
		int cnt = ans[i - 1];
		rest = rest - cnt * (a[i] - a[i - 1]);
		while(rest < 0){
			rest = rest + (a[i] - a[j]);
			j++; cnt--;
		}
		ans[i] = i - j + 1;
		res = max(res, ans[i]);
	}
	cout << res;
//	vector <int> de;
//	for(int i = 1; i <= n; i++){
//		cout << ans[i] << '\n';
//		if(ans[i] == 5000)
//		de.push_back(i); 
//	}
//	for(auto x : de) cout << "sss : " << x;
//cout << (sizeof(a) + sizeof(ans)) / 1024 / 1024;
	return 0;
}
