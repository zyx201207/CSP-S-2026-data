#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q;
long long w[N],k[N],t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			long long x;
			cin >> x >> t;
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+2*t << '\n'; 
	}
	return 0;
}
