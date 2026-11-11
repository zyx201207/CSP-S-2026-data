#include <bits/stdc++.h>
using namespace std;
int c , t , n , cnt;
long long zdlj[5005][5005] , x[2000005];
long long d;
long long js[5005][5005];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(x[j] - x[i] <= d){
					if(i == j)continue;
					zdlj[i][j] = 1;

					}
				}
			}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int k = 1;k <= n;k++){
					if(i == j || i == k || j ==k)continue;
					if(zdlj[i][j] != 0 && zdlj[j][k] != 0 && zdlj[i][k] == 0){
						zdlj[i][k] = zdlj[i][j] + zdlj[j][k];
					}
				}
			}
		}

		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					if(zdlj[i][j] + zdlj[j][k] == zdlj[i][k])js[i][k]++;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(js[i][j] == 2){
					cnt++;
				}
			}
		}
		cout << cnt<<endl;
		
	}
}
