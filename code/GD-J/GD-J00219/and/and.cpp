#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans;
int a[200005];
int q[2][200005];
int t[2];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		q[1][++t[1]] = a[i];
	}
	for(int bit = 30; bit >= 0; bit--){
		int noww = bit % 2;
		t[noww] = 0;
		int cnt = 0;
		
		for(int i = 1; i <= t[noww ^ 1]; i++){
			if(((q[noww ^ 1][i] >> bit) & 1) == 1){
				cnt++;
			}
		}
		
		if(cnt >= m){
			for(int i = 1; i <= t[noww ^ 1]; i++){
				if(((q[noww ^ 1][i] >> bit) & 1) == 1){
					q[noww][++t[noww]] = q[noww ^ 1][i];
				}
			}
			ans += (1 << bit);
		}
		else{
			for(int i = 1; i <= t[noww ^ 1]; i++){
				q[noww][++t[noww]] = q[noww ^ 1][i];
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}
