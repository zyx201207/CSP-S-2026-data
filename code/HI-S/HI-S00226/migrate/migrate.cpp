#include<bits/stdc++.h>
using namespace std;
int c = 0, t = 0, n = 0;
long long d = 0;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		bool f = true;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(a[n]-a[1] <= d){
			int k = n-3;
			cout << (k+1)*k/2 << endl;
			continue;
		}
		int q = a[2] - a[1];
		for(int i = 2; i <= n; i++){
			if(a[i] - a[i-1] != q){
				f = false;
			}
		}
		if(f){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(i+3 <= n){
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
