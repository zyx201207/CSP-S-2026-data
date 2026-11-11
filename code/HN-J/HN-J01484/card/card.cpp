#include<bits/stdc++.h>

using ll = long long;
#define f first
#define s second
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 2e5 + 10;
int n, m, a[N], cnt[N];
bool vis[N];
std::stack<int> st;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) {
		std::fill(vis + 1, vis + m + 1, false);
		for (int j = i; j <= n; j++) if (!vis[a[j]]) st.push(a[j]), vis[a[j]] = true;
		else {
			while (!st.empty()) {
				int x = st.top();
				st.pop();
				if (x == a[j]) break;
				vis[x] = false;
			}
			st.push(a[j]);
		}
		while (!st.empty()) cnt[st.top()]++, st.pop();
	}
	for (int i = 1; i <= m; i++) std::cout << cnt[i] << " \n"[i == m];
	return 0;
} 
