#include <bits/stdc++.h>

int N, M, arr[200010], LN = 30, vis[200010], ans = 0;

int main() {
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	std::cin >> N >> M;
	for (int i = 1; i <= N; i ++) std::cin >> arr[i], vis[i] = 1;
	for (int j = LN; j >= 0; j --) {
		int cnt = 0;
		for (int i = 1; i <= N; i ++) if ((arr[i] & (1 << j)) && vis[i]) cnt ++;
		if (cnt >= M) {
			for (int i = 1; i <= N; i ++) if (!(arr[i] & (1 << j))) vis[i] = 0;
			ans += (1 << j);
		}
	}
	
	std::cout << ans;
	return 0;
}
