// gu fen : 48 ~ 56
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int q[N], dl = 1, dr = 1, ans[N], cx[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		dr = 0;
		for(int j = 1; j <= m; j++) cx[j] = 0;
		for(int j = n; j >= i; j--) cx[a[j]] = max(cx[a[j]], j);
		for(int j = i; j <= n;){
			q[++dr] = a[j];
			j = cx[a[j]] + 1;
			// 黄紫黑黑 
		}
		for(int j = 1; j <= dr; j++) ans[q[j]]++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
}
// 达成时间：10:40
// 评级： green
