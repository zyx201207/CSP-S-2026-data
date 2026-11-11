//GZ-J00144  张心恬  贵阳市白云区华师一学校
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, x[N], vis[M], r, ans[M], maxn;
int a[N];
void clean(int t){
	int xh = 0, tmp = r;
	for (int i = 1; i <= r; i ++ ){
		if (a[i] == t){
			xh = 1;
		}
		if (xh){
			tmp -- ;
			vis[a[i]] = 0;
			a[i] = 0;
		}
	}
	r = tmp;
	return ;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ){
		cin >> x[i];
	}
	for (int i = 1; i <= n; i ++ ){
		memset(vis, 0, sizeof(vis));
		memset(a, 0,sizeof(a));
		r = 0;
		for (int j = i; j <= n; j ++ ){
			maxn = max(maxn, x[j]);
			if (vis[x[j]]){
				clean(x[j]);
			}
			vis[x[j]] = 1;
			a[ ++ r] = x[j];
		}
		for (int j = 1; j <= m; j ++ ){
			ans[j]+= vis[j]; 
		}
	}
	for (int i = 1; i <= m; i ++ ){
		cout << ans[i] << " ";
	}
	return 0;
} 
