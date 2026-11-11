#include <bits/stdc++.h>
#define int long long
using namespace std;
string x, y, z, w;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> x >> y >> z >> w; 
	if(x == z) {
		cout << 1;
		
	}else {
		cout << 0;
	} if(x == z && y[0] == w[0] && y[1] == w[1]) {
		cout << 1;
	} else {
		cout << 0;
	} if(x == z && y[0] == w[0] && y[1] == w[1]) {
		if(y[2] >= 'D' && w[2] >= 'D' || y[2] <= 'C' && w[2] <= 'C') {
			cout << 1;
		}  else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	if(x == z && y[0] == w[0] && y[1] == w[1]) {
		if(y[2] >= 'D' && w[2] >= 'D' || y[2] <= 'C' && w[2] <= 'C') {
			if(abs(y[2] - w[2]) == 1) cout << 1;
			else cout << 0; 
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}
