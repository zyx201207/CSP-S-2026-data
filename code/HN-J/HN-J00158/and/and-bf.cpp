#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 25;

int n, m;
int a[MAXN];

int ans;

void dfs(int i, int cnt, int And) {
	if(i == n + 1) {
		if(cnt == m)ans = max(ans, And);
		return;
	}
	dfs(i + 1, cnt, And);
	dfs(i + 1, cnt + 1, And & a[i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, (1 << 30) - 1);
    cout << ans;
    return 0;
}
