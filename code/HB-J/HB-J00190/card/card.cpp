#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 5, M = 3e5 + 5;
ll n, m, x[N], tot[M], buck[M], pos[M];

void play(int k) {
	for (int i = k; i <= n; i++) {
		if (buck[x[i]]) {
			for (int j = pos[x[i]]; j <= i; j++) {
				buck[x[j]] = 0;
			}
			buck[x[i]] = 1;
			pos[x[i]] = i;
		}
		else {
			buck[x[i]] = 1;
			pos[x[i]] = i;
		}
	}
	cout << endl;
	for (int i = 1; i <= m; i++) tot[i] += buck[i], buck[i] = 0, pos[i] = 0;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) play(i);
	for (int i = 1; i <= m; i++) cout << tot[i] << ' ';
	return 0;
}
