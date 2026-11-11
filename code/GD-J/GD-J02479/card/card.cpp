#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;

int a[N], card_desk[N], idx_desk = 0, pos[M], n, m, cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		idx_desk = 0;
		memset(pos, 0, sizeof pos);
		for(int j = i;j <= n;j++) {
			if(pos[a[j]] && pos[a[j]] <= idx_desk) {
				idx_desk = pos[a[j]];
			}
			else {
				if(pos[card_desk[++idx_desk]] >= idx_desk) pos[card_desk[idx_desk]] = 0;
				card_desk[idx_desk] = a[j];
				pos[a[j]] = idx_desk;
			}
		}
		for(int j = 1;j <= idx_desk;j++) {
			cnt[card_desk[j]]++;
		}
	}
	for(int i = 1;i <= m;i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
