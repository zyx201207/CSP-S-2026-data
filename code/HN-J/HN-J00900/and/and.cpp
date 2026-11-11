#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans, a[N];
int cnt[30], s[30][N], b[30][N], nw[30];
bool vis[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i <= 29; i++){
		for(int j = 1; j <= n; j++){
			if((a[j] >> i) & 1){
				cnt[i]++, s[i][j]++;
				continue;
			}
			b[i][++nw[i]] = j;
		}
	}
	for(int i = 29; i >= 0; i--){
		if(cnt[i] >= m){
			ans += (1 << i);
			for(int j = 1; j <= nw[i]; j++){
				if(vis[b[i][j]]) continue;
				for(int k = 0; k <= 29; k++) cnt[k] -= s[k][b[i][j]];
				vis[b[i][j]] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
