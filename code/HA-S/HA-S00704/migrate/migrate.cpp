#include <bits/stdc++.h>
using namespace std;
int c,t;
int x[5000];
bool can[5000][5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out", "w",stdout);
	cin >> c >> t;
	while(t--){
		memset(can, 0, sizeof(can));
		int n,d;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++){
			cin >> x[i];
		}
		int last = 1;
		for(int i = 1; i < n; i ++){
			if(x[i + 1] - x[i] <= d){
				can[i][i + 1] = 1;
				for(int j = last; j <= i; j ++){
					can[j][i+1] = 1;
				}
			}else{
				last = i + 1;
			}
		}
		int sum = 0;
		for(int i = 1; i <= n ; i++){
			for(int j = i+3; j <= n; j++){
				int dif = x[j] - x[i];
				if(can[i][j]){
					if(dif % d != 0){
						sum ++;	
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
