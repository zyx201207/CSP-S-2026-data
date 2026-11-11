#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL c,n,m,d,q;
LL w[500010];
vector<LL> a[505],t[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(LL i=1;i<=m;i++)cin >> w[i];
	for(LL i=1;i<=n;i++){
		LL k;cin >> k;
		for(LL j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
		
	}
	
	for(LL i=1;i<=q;i++){
		
	}

	return 0;
}

