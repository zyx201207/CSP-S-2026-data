#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;

int n, m, cnt;
int a[N], lst[M], t[N], ans[M];
bool vis[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++){
		memset(t, 0, sizeof t);
		memset(vis, 0, sizeof vis);
		memset(lst, 0, sizeof lst);
		for(int j = i; j <= n; j ++){
			if(lst[a[j]] != 0){
				t[lst[a[j]]] ++, t[j] --;
				for(int k = lst[a[j]]; k <= j - 1; k ++)
					lst[a[k]] = 0;
			}
			lst[a[j]] = j; 
		}
		for(int j = i; j <= n; j ++){
			t[j] += t[j - 1];
			if(t[j] == 0) vis[a[j]] = 1;
		}
		for(int j = 1; j <= m; j ++)
			if(vis[j]) ans[j] ++;
	}
	for(int i = 1; i <= m; i ++)
		cout << ans[i] << ' ';
	return 0;
}

