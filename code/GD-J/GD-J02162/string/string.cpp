#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
char c[200100];
vector<pair<int, char> > a;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	ll len = 0;
	for(int i = 1, x; i <= n; i ++) cin >> x >> c[i], a.push_back({x, c[i]}), len += x;
	vector<pair<int, char> > v = a;
	reverse(v.begin(), v.end());
	int p1 = 0, p2 = 0;
	ll lst_1 = 0, lst_2 = 0, flst = 0;
	ll ans = 0;
	while(1) {
		if(lst_1 >= len / 2 || lst_2 >= len / 2) break;
		// cout << p1 << ' ' << p2 << ' ' << endl;
		ll rp1 = lst_1 + a[p1].first, rp2 = lst_2 + v[p2].first;
		ll winln = min(rp1, rp2) - max(lst_1, lst_2);
		// cout << winln << endl;
		if(a[p1].second != v[p2].second) ans += winln;
		if(rp1 <= rp2) lst_1 = rp1, p1 ++;
		else lst_2 = rp2, p2 ++;
		
	}
	cout << ans;
	return 0;
} 
// 神了，这能搓出正解 
