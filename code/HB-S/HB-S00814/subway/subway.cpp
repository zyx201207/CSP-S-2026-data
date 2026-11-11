#include <bits/stdc++.h>
using namespace std;
const long long MAXM=5e5+5,MAXQ=1e5+5;
long long c,n,m,d,q,w[MAXM],a[MAXM][MAXM],t[MAXM][MAXM],x[MAXQ],y[MAXQ];
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) {
		int k1;
		cin>>k1;
		for (int j=1;j<=2*k1+1;j++) cin>>a[i][j]>>t[i][j];
		
	}
	for (int i=1;i<=q;i++) cin>>x[i]>>y[i];
	
	
	
	return 0;
}
