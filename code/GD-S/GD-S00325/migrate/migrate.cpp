#include <iostream>
using namespace std;
const int N = 5050;
int c, t, n, d, a[N], sum[N][N], ans[N][N];
bool vis[N][N], vis2[N][N];//vis是有没有过，vis2是有没有两次以上 
void f(int x, int w){
	
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> a[i];
			}
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					sum[i][j] = 0x3f3f3f3f;
					vis[i][j] = false;
					vis2[i][j] = false;
				}
			}
			int ans = 0;
			for(int i =1; i <= n; i++){
				sum[i][i] = 0;
				for(int j = i + 1; j <= n; j++){
					if(a[j] - a[i] <= d){
						sum[i][j] = 1;
					}
				}
			}
		//	cout << a[3] << " " << a[1] << " " << a[3]-a[1] << " " << t << endl;
		//	cout << sum[1][3] << endl << endl;
			for(int i = 1; i <= n; i++){
				for(int j = i + 2; j <= n; j++){
					for(int k = i + 1; k < j; k++){
						if(sum[i][k] + sum[k][j] == sum[i][j]){//有其它最短路 
							if(vis[i][j] == false && vis2[i][j] == false){//双次 
								ans++;
								vis[i][j] = true;
							}else if(vis[i][j] == true && vis2[i][j] == false){
								vis[i][j] = false;
								vis2[i][j] = true;
								ans--;
							}
							
						}else if(sum[i][k] + sum[k][j] < sum[i][j]){
							if(vis[i][j] == true){
								vis[i][j] = false;
								ans--;
							}
							vis2[i][j] = false;
							sum[i][j] = sum[i][k] + sum[k][j];
						}
					}
				}
			}
			cout << ans << endl;
		}
	return 0;
} /*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/
