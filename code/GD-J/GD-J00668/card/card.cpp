#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , t[500005] , vis[300005] , ans[500005] , cnt;
int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	for(long long i = 1;i <= n;i++) {
		cnt = 0;
		memset(vis , 0 , sizeof(vis));
		for(long long j = i;j <= n;j++) {
			if(vis[a[j]] == 0 || vis[a[j]] > cnt) {
				vis[a[j]] = ++cnt;
				t[cnt] = a[j];
			}
			else {
				cnt = vis[a[j]];
				t[cnt] = a[j];
			}
		}
		for(long long j = 1;j <= cnt;j++) ans[t[j]]++;
	}
	for(long long i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
