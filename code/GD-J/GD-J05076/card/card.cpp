#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;

int a[N], cnt[M];
bool in[M];
stack<int> st;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(in, false, sizeof(in));
		for (int j = i; j <= n; j++) {
			if (in[a[j]]) {
				int x = 0;
				while(x != a[j] && !st.empty()) {
					x = st.top();
					st.pop();
					in[x] = false;
				}
				st.push(a[j]);
				in[a[j]] = true;
			} else {
				st.push(a[j]);
				in[a[j]] = true;
			}
		}
		while (!st.empty()) {
			cnt[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' '; 
	}
	
	return 0;
	
} 
