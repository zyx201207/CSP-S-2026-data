#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1000*1000*1000*1000*1000*1000+1;
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		long long n,d;
		long long a[2000005] = {};
		memset(a,maxn,sizeof(a));
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		long long i = 1,j = 1;
		int o = 0;
		long long cnt = 0,ans = 0;
		for (i = 1; i <= n; i++){
			for (j = i+1; j <= n; j++){
				cnt = 0;
				for (long long k = i+1; k <= j-1; k++){
					if(a[k] - a[i] <= d && a[j] - a[k] <= d){
						cnt++;
					}
				}
				if(cnt == 2) ans++;
			}
		}
		cout << ans << endl;; 
	}
	return 0;
} 
