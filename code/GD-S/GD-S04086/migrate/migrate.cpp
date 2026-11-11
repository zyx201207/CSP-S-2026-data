#include <bits/stdc++.h>

using namespace std;

const int N = 5 * 1e5 + 100;
const int M = 5 * 1e3 + 100;
int c, t, n, d;
int a[N];
int b[M][M];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		} 
		cout << 0;
//		for(int i = 1; i <= n; i++){
//			for(int j = i; j >= 1; j--){
//				b[i][1] = j;
//				if(a[i] - a[j - 1] > d){
//					break;
//				}
//			}
//		}
//		for(int j = 2; j <= n; j++){
//			for(int i = 2; i <= n; i++){
//				b[i][j] = max(1, b[b[i][j - 1]][1]);
//			}
//		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 2; j <= n; j++){
//				if(b[i][j] == b[i][j - 1]){
//					continue;
//				}
//				if(b[i][j] == b[i][j + 1]) {
//					tt[i] ++;
//				}
//			}
//		}
//		for(int i = 1; i <= n; i++){
//			for(int j = i + 1; j <= n; j++){
//				if(a[j] - a[i] > d){
//					break;
//				}
//				for(int k = i + 1; k <= j; k++){
//					if(d[i][k] + d[k][j] == d[i][j])
//				}
//			}
//		}
	}
	return 0;
}

