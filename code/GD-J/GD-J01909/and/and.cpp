#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[200005], ans;
bool pass[200005], bl[35];
bool tw[35][200005];//前是位数，后是a[i] 
int main(){
//	freopen("and5.in", "r", stdin);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		pass[i] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int j = 1;
		while(a[i] != 0){
			tw[j][i] = a[i] % 2;
			a[i] /= 2;
			j++;
		}
	}
	for(int i = 30; i >= 1; i--){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			cnt += (tw[i][j] && pass[j]);
		}
		if(cnt >= m){
			bl[i] = 1;
			for(int j = 1; j <= n; j++){
				pass[j] = (pass[j] && tw[i][j]);
			}
		}
	}
	for(int i = 1; i <= 30; i++){
		ans += pow(2, i - 1) * bl[i];
	}
	cout << ans;
	return 0;
}
//m <= n <= 200000, a[i] <= 2 ^ 30
