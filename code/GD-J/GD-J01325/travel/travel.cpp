#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c1, c2;
string s1, s2, ans = "";

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2) {
		ans = "0000";
	} else {
		ans += "1";
		ll x = stoll(s1.substr(0, 2));
		ll y = stoll(s2.substr(0, 2));
		if (x != y) {
			ans = "1000";
		} else {
			ans += "1";
			char posx = s1.back();
			char posy = s2.back();
			if (posx <= 'C' && posy >= 'D' || posx >= 'D' && posy <= 'C') {
				ans = "1100"; 
			} else {
				ans += "1";
				if (abs(posx - posy) == 1) {
					ans = "1111";
				} else {
					ans = "1110";
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}

