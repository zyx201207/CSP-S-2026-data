#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d;
long long x[2000005];
long long dp[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t ;
	for (int i = 1; i <= t; i++){
		cin >> n >> d;
		for (int j = 1; j <= n; j++){
			cin >> x[j];
		}		
		if(x[1] + d >= x[n]){
			cout << "0\n";
			continue;
		}
		for (int j = 1; j <= n; j++){
			long long k = x[j] + d;
			int p = upper_bound(x+1,x+n+1,x[j]+d)-x-1;
			for (int h = j;h <= p; h++){
				dp[h]++;
			}
			//int p2 = upper_bound(x+1,x+n+1,x[p-1]+d)-x-1;
			//cout << p << endl;
			//ans += (p-1-j)*(p2-p);
		}
		//int k = 
	}
	for (int i = 1;i <= n; i++){
	//	cout << dp[i] << " ";
	}
	//cout << ans ;
	return 0;
}
