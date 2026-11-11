#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], num[N], ans[N];
bool v[N];
void solve_1() { // subtask 1 ~ 6
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= max(n, m); j++) 
			num[j] = 0, v[j] = true;
		for(int j = i; j <= n; j++) {
			if(!num[a[j]]) num[a[j]]++;
			else {
				num[a[j]]++;
				for(int k = j - 1; k >= i; k--) {
					if(!v[k]) continue;
					if(a[k] == a[j]) break;
					num[a[k]]--, v[k] = false;
				}
			}
		}
		for(int j = 1; j <= m; j++) ans[j] += (num[j] > 0);
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	solve_1();
	return 0;
}
