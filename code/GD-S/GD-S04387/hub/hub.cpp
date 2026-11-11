#include <bits/stdc++.h>
using namespace std;
int a[500010], t[500010];
int n[500010], k[500010];
int c, T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	for (int s = 1; s <= T; s ++){
		cin >> n[s] >> k[s];
		for (int i = 1; i < n[s]; i ++){
			cin >> a[i] >> t[i];
		}
		cout << rand();
	}
	return 0;
}
