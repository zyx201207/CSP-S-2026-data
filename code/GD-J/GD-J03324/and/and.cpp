#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,m;
int x[maxn],sum[32];
bool a[maxn][32],pass[maxn]; 
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> x[i];
		for (int j = 30;j >= 0;j--){
			if (x[i] & (1<<j)){
				a[i][j] = 1;
				sum[j]++;
			}
			//cout << a[i][j];
		}
		//cout << '\n';
	}
	
	int ans = 0;
	for (int mj = 30;mj >= 0;mj--){
		if (sum[mj] >= m){
			ans += (1<<mj);
			for (int i = 1;i <= n;i++){
				if (!a[i][mj]) pass[i] = true;
			}
			
			memset(sum,0,sizeof(sum));
			for (int i = 1;i <= n;i++){
				if (pass[i]) continue;
				for (int j = 30;j >= 0;j--){
					if (x[i] & (1<<j)){
						sum[j]++;
					}
				}
			}
		}	
	}
	cout << ans;
}
