#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
int ans[300005];
void f1() {
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		int cnt[300005] = {0};
		bool vis[300005] = {0};
		for(int j = i;j <= n;j++) {
			cnt[a[j]]++;
			vis[j] = true;
			if(cnt[a[j]] > 1) {
				bool flag = false;
				for(int k = i;k <= j-1;k++) {
					if(a[k] == a[j] && vis[k] == true) flag = true;
					if(flag && vis[k] == true) cnt[a[k]]--,vis[k] = false;
				}
			}
		}
		for(int i = 1;i <= m;i++) {
			if(cnt[i] == 1) ans[i]++;
		}
	}
	for(int i = 1;i <= m;i++) {
		cout << ans[i] << " ";
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	f1();
	
	return 0;
}
