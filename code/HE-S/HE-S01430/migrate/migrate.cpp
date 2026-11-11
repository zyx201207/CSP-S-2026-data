#include <bits/stdc++.h>
using namespace std;

int c, t, nn, d, f, ff, sjs, ans;
int n[310], dd[310], dp[310];

void ddd(){
	while (ff - f >= 0){
		if (n[ff] - n[ff - f] <= d){
			dd[ff] = ff - f;
			f++;
		}else{
			return;
		}
	}
	return;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> nn >> d;
		cin >> n[0];
		ans = 0;
		for (int i = 1; i < nn; i++){
			cin >> n[i];
			f = 1;
			ff = i;
			ddd();
			 cout << dd[ff] << " ";
		}
		for (int i = 0; i < nn - 3; i++){
			dp[i] = 0;
			dp[i + 1] = 1;
			if(dd[i + 2] <= i){
				dp[i + 2] = 1;
			}else{
				dp[i + 2] = 2;
			}
			for (int j = i + 3; j < nn; j++){
				if (dd[j] <= i){
					dp[j] = 1;
				}else{
					dp[j] = dp[dd[j]] + 1; 
					sjs = 1;
					for (int k = dd[j] + 1; k < j; k++){
						if (dp[k] == dp[dd[j]]){
							sjs++;
						}
					}
					if (sjs == 2){
						ans++;
					}
				}
			}
		}
		cout << endl << ans << endl;
	}
	return 0;
} 
