#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string a, b, c, d, ans = "";
	cin >> a >> b >> c >> d;
	if(a == c) {
		ans += "1";
		bool flag = true;
		for(int i = 0; i < 2; i++) {
			if(b[i] != d[i]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			ans += "1";
			if((b[2] <= 'C' && b[2] >= 'A' && d[2] <= 'C' && d[2] >= 'A') || ((b[2] == 'F' || b[2] == 'D') && (d[2] == 'D' || d[2] == 'F'))) {
				ans += "1";
			}else {
				ans += "0";
			}
		}else {
			ans += "00";
		}
		if(ans == "111"){
			if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'F' && d[2] == 'D')) {
				ans += "1";
			}else {
				ans += "0";
			}
			cout << ans << '\n';
		}else {
			ans += "0";
			cout << ans << "\n";
		}
	}else {
		ans += "0000";
		cout << ans << '\n';
	}
	return 0;
}
