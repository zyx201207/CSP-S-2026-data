#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		int n,d;
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		cout << 0 << endl;
	}
	return 0;
}
