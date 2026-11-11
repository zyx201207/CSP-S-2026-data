#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int ans = 0;
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				if((a[j]-a[i])/d == 1 && (a[j]-a[i])%d == 1) ans++;
			}
		}
		cout << ans << endl;
	}
			
	return 0;
}

