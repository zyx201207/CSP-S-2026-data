#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
using namespace std;
string c1, c2, c3, c4; 
void solve() {
	cin >> c1 >> c2 >> c3 >> c4;
	int x, y;
	x = (int)c2[2], y = (int)c4[2];
	if(c1 != c3) cout << "0000\n";
	else {
		if(c2[0] != c4[0] || c2[1] != c4[1]) cout << "1000\n";
		else {
			if((c2[2] >= 'A' && c2[2] <= 'C' && c4[2] >= 'D' && c4[2] <= 'F') || (c2[2] >= 'D' && c2[2] <= 'F' && c4[2] >= 'A' && c4[2] <= 'C')) cout << "1100\n";
			else {
				if(x - 1 != y && x + 1 != y) cout << "1110\n";
				else cout << "1111\n";
			}
		}
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--) solve();
	return 0;
}

