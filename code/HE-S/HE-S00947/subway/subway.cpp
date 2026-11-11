#include<bits/stdc++.h>
using namespace std;
long long w[500010];
set<int> s;
struct PII {
	int a,t;
};
map<int,PII> a;
int main() {
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		int k,x,t;
		cin >> k;
		for(int j=1; j<=k; j++) {
			cin >> x >> t;
			a[i]= {x,t};
		}
	}
	while(q--) {
		int x,y;
		cin >> x >> y;
	}
	return 0;
}
