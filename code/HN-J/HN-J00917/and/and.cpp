#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], hd[30], nxt[6000005], val[6000005], cnt[30], pt, ans;
bool vis[200005];

void del(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for( int i = 0; i < 30; i++ ){
		if((a[x] >> i) & 1) cnt[i]--;
	}
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ) cin >> a[i];
	for( int i = 1; i <= n; i++ ){
		for( int j = 0; j < 30; j++ ){
			if(!((a[i] >> j) & 1)){
				nxt[++pt] = hd[j];
				val[pt] = i;
				hd[j] = pt;
			}
			else cnt[j]++;
		}
	}
	for( int i = 29; i >= 0; i-- ){
		if(cnt[i] < m) continue;
		for( int j = hd[i]; j; j = nxt[j] ) del(val[j]);
		ans += (1 << i);
	}
	cout << ans << '\n';
	return 0;
}
