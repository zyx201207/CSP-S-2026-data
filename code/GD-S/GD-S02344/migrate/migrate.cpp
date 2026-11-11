#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 10;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	long long c,t;
	cin >> c >> t;
	while(t--){
		long long n,d;
		long long ans = 0;
		cin >> n >> d;
		for(long long i = 1;i <= n;i++){
			cin >> a[i];
		} 
		for(long long i = 1;i <= n;i++){
			long long cnt = 0;
			for(long long j = i+1; j <= n; j++){
				if(d < a[j]-a[i]) break;
				else{
					cnt++;
				}	
			}
			if(cnt == 2) ans++;
		}
		cout << ans-1 << "\n";
	} 
	return 0;
}
