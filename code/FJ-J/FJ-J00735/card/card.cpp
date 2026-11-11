#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int a[N];
int n, m;
int cnt[N];
bool vis[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	deque<int> q;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (vis[a[j]]){
				while (!q.empty() && q.back() != a[j]){
					vis[q.back()] = 0;
					q.pop_back();
				}
			}else {
				q.push_back(a[j]);
				vis[a[j]] = 1;
			}
		}
		for (int i = 1; i <= m; i++){
			cnt[i] += vis[i];
		}
		while (!q.empty()){
			vis[q.back()] = 0;
			q.pop_back();
		}
	}
	for (int i = 1; i <= m; i++) printf("%lld ", cnt[i]);
	return 0;
}
