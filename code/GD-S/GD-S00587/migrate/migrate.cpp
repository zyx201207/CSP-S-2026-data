#include <bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdin);
	int c, T;
	cin >> c >> T;
	long long ans = 0;
	while(T--){
		int n, d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n-4;i++){
			if(x[i+3]-x[i] <= d){
				ans++;
			}
		}
		cout << ans << '\n';
		memset(x,0,sizeof(x));
	}
	return 0;
}
