/* record
8:46 ±£Áô½ÚÄ¿ 
8:57 ÇĞ A 
*/
#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

string n, m, u, v;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> u >> m >> v;
	
	int k = (n == m);
	if (k) cout << 1;
	else cout << 0;
	
	int f = (u[0] == v[0] && u[1] == v[1]);
	int g = (((u[2] < 'D') && (v[2] < 'D')) || ((u[2] >= 'D') && (v[2] >= 'D')));
	
	if (f && k) cout << 1;
	else cout << 0;
	if (g && f && k) cout << 1;
	else cout << 0;
	if (k && f && g && abs(u[2] - v[2]) == 1) cout << 1;
	else cout << 0;

	return 0;
}

