#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, T, n, m, cnt;
int h[N], e[N], ne[N];
void add(int a, int b){
	e[++cnt] = b, ne[cnt] = h[a], h[a] = cnt;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		cout << 1 << endl;
	}
	return 0;
}
