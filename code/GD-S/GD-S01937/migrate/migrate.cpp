#include <bits/stdc++.h>
using namespace std;
int c, T;
long long n, d, ans;
long long a[10005];
long long f[10005][10005], minn[10005][10005];
long long pre[10005];
int main(){
//	freopen("migrate5.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		ans = 0;
		int x = 1;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			while(a[i] - a[x] > d){
				x++;
			}
			pre[i] = x;
//			cout << pre[i] << ' ';//
		}
//		cout << endl;//
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[j - 1] > d){
					break;
				}
				else if(a[j] - a[i] <= d){
					f[i][j] = 1;
					minn[i][j] = 1;
				}
				else{
					f[i][j] = 0;
					for(int l = pre[j]; l < j; l++){
						if(minn[i][l] != minn[i][pre[j]]){
							break;
						}
						f[i][j] += f[i][l];
					}
					minn[i][j] = minn[i][pre[j]] + 1;
				}
//				cout << i << ' ' << j << ' ' << f[i][j] << ' ' << minn[i][j] << endl;//
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				ans += (f[i][j] == 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
