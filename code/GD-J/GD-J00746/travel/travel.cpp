// difficulty: red / *800
// tags: simulation
#include <bits/stdc++.h>
#define int long long
using namespace std;
string C_R, S_R, C_X, S_X; 
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> C_R >> S_R;
	cin >> C_X >> S_X;
	
	if (S_R[2] == 'F') S_R[2] = 'E';
	if (S_X[2] == 'F') S_X[2] = 'E';
	
	if (C_R != C_X) {
		cout << "0000";
		return 0;
	}
	
	cout << 1;
	if (S_R[0] != S_X[0] || S_R[1] != S_X[1]) {
		cout << "000";
		return 0;
	}
	
	cout << 1;
	if ((S_R[2] <= 'C' && S_X[2] >= 'D') || (S_R[2] >= 'D' && S_X[2] <= 'C')) {
		cout << "00";
		return 0; 
	}
	cout << 1;
	
	if (S_R[2] - S_X[2] >= 2 || S_R[2] - S_X[2] <= -2) cout << 0;
	else cout << 1;
	return 0;
}
