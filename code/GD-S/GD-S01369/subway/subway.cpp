#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout)
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int ans = 0;
	for (int i = 1;i <= m;i++){
		int w;
		cin >> w;
		ans += w;
	}
	for (int i = 1;i <= k;i++){
		int a,t;
		cin >> a >> t;
		sum += t;
	}
	while (q--){
		cout << sum << "\n";
	}
	return 0;
}
