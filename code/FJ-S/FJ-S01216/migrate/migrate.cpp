#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if(c <= 25){
		while(t --){
			int n, d;
			cin >> n >> d;
			vector<int> x(n);
			for(int i = 0; i < n; i ++){
				cin >> x[i];
			}
			int l = 0, r = 1;
			int ans = 0;
			vector<vector<bool>> twice(n, vector<bool> (n, false));
			vector<vector<int>> dis(n, vector<int> (n, 0));
			int be = 0;
			for(int i = 1;  i < n && x[i] - x[0] <= d; i ++){
				if(i < n && x[i] - x[0] <= d){
					dis[0][i] = 1;
				}
			}
			if(n > 0){
				dis[0][0] = 0;
			}
			while(r < n){
				while(x[r] - x[l] > d){
					l ++;
				}
				for(int i = be; i < l; i ++){
					dis[i][r] = dis[i][l] + 1;
				}
				for(int i = l; i < r; i ++){
					dis[i][r] = 1;
				}
				dis[r][r] = 0;
				if(r == l){
					be = l;
					r ++;
					continue;
				}
				if(l == r - 1){
					for(int i = be; i < l; i ++){
						if(twice[i][l]){
							twice[i][r] = true;
//							cout << i << " ->" << r << endl;
							ans ++;
						}
					}
				}
				else if(l == r - 2){
					for(int i = be; i < l; i ++){
						if(dis[i][l] == dis[i][l + 1] && !twice[i][l] && !twice[i][l + 1]){
							twice[i][r] = true;
//							cout << i << " ->" << r << endl;
							ans ++;
						}
					}
			    }
				else{
//			    	int min_ = INT_MAX;
//			    	int sum = 1;
					for(int i = be; i < l; i ++){
						if(dis[i][l] == dis[i][l + 1] && dis[i][l] < dis[i][l + 2] && !twice[i][l] && !twice[i][l + 1] || (dis[i][l] != dis[i][l + 1] && twice[i][l])){
							twice[i][r] = true;
//							cout << i << " ->" << r << endl;
							ans ++;
						}
//						for(int j = l; j < r; j ++){
//							if(dis[i][j] < min_){
//								min_ = dis[i][j];
//								sum = 1;
//							}else if(dis[i][j] == min_){
//								sum ++;
//							}
//						}
//						if(sum == 2){
//							twice[i][r] = true;
////							cout << i << " ->" << r << endl;
//							ans ++;
//						}
					}
				}
				//cout << "[" << l << ", " << r << "]" << endl;
				r ++;
			}
			cout << ans << endl;
//			for(int i = 0; i < n; i ++){
//				for(int j = i; j < n; j ++){
//					//cout << dis[i][j] << " ";
//				}
//				cout << endl;
//			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
