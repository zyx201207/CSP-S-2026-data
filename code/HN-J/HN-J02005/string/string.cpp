#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << endl;

using namespace std;
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0); 
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, char>>ve(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> ve[i].first;
		cin >> ve[i].second;
	}
	int l = 1, r = n;
	ll ans{};
	while (l < r) {
		int tmp = min(ve[l].first, ve[r].first);
		ve[l].first -= tmp;
		ve[r].first -= tmp;
		if(ve[l].second != ve[r].second){
			ans += tmp;
		}
		if(ve[l].first == 0){
			l++;
		}
		if(ve[r].first == 0){
			r--;
		}
	}
	cout << ans << '\n';
	return 0;
} 
