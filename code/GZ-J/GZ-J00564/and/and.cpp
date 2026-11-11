//GZ-J00564  毕节七星关东辰实验学校  李浩辰

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
ll n, m, a[maxn], ans = -1e6;
void y(int q){
	for(int i = 1; i <= n; i++){
		if(a[i] == q) continue;
		ll maxn1 = q & a[i];
		ans = max(maxn1, ans);
	}
}
void y1(int q, int x, int y){
	for(int i = 1; i <= n; i++){
		if(a[i] == x || a[i] == y) continue;
		ll maxn1 = q & a[i];
		ans = max(maxn1, ans);
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1) for(int i = 1; i <= n; i++) ans = max(a[i], ans);
	else if(m == 2) for(int i = 1; i <= n; i++) y(a[i]);
	else{
		for(int i = 1; i <= m - 2; i++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j) continue;
					y1(a[i] & a[j], a[i], a[j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
