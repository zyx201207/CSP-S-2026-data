#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		cout << n-d-1 << '\n';
	}
	return 0;
}
