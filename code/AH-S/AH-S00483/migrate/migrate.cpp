#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, ans;



int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "W", stdout);
    cin >> c >> t;
    for(int T = 0; T < t; T++){
		ans = 0;
		cin >> n >> d;
		long long xian[n + 5], cha[n + 5], f[n + 5] = {0};
		for(int i = 0; i < n; i++){
			cin >> xian[i];
			if(i!=0) cha[i] = xian[i] - xian[i-1];
		}
		f[0] = 1;
		f[1] = 1;
		for(int i = 2; i < n; i++){
			for(int j = 1; j < d; j++){
				if(j < d-1){
					continue;
				}
				else{
					f[i] += f[i-j];
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(f[j-i] == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
    
    
    
    
    
    return 0;
}
