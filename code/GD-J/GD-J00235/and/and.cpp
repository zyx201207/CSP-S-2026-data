#include <bits/stdc++.h>
using namespace std; 
int n,m;
long long a[200005],ans = 0;
void dfs(int p,int cnt,long long sum) {
    if (p > n) {
        if (cnt == m) ans = max(ans,sum);
        return ;
    }
    if (cnt > m) return ;
    dfs(p + 1,cnt,sum);
    if (cnt < m) {
        if (sum == 0) {
            dfs(p + 1,cnt + 1,a[p]);
        } else {
            dfs(p + 1,cnt + 1,sum & a[p]);
        }
    }
}
int c[200005];
bool vis[200005];
void solve(int p) {
    if (p > m) {
        long long tmp = 0;
        for (int i = 1;i <= m;i++) {
            if (i == 1) tmp = a[c[i]];
            else tmp = tmp & a[c[i]];
        }
        ans = max(ans,tmp);
        return ;
    }
    for (int i = 1;i <= n;i++) {
        if (vis[i]) continue;
        vis[i] = true;
        c[p] = i;
        solve(p + 1);
        vis[i] = false;
        c[p] = 0;
    }
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (log(n) * m <= 16.0) {
        solve(1);
	} else {
        dfs(1,0,0);
	}
    cout << ans;
    return 0;
}

