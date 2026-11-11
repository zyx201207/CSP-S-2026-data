#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int n, m, a[(int)5e5 + 5], pre[(int)5e5 + 5];
int check(int x){
	vector<int> tmp;
	for(int i = 1;i <= n && a[i] <= x;i++){
		tmp.push_back(x - a[i]);
	}
	sort(tmp.begin(), tmp.end());
	int cnt = 0, res = 0;
	for(int i : tmp){
		if((cnt += i) > m) break;
		res ++;
	}
	return res;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1);
	//for(int i = 1;i <= n;i++){
	//	cout << (pre[i] = a[i] - a[i - 1]) << ' ' ;
	//}
	int ans = 0, cnt = 0, tot = 0;
	for(int i = 1, j = 1;i <= n;i++){
		cnt += a[i]; tot ++;
		for(;j < i && a[i] * tot - cnt > m;cnt -= a[j++], tot--);
		ans = max(ans, tot);
	}
	cout << ans << '\n';
	return 0;
}
