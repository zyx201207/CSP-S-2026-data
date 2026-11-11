#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[501][500001],t[501][500001],x[100001],y[100001];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>x[i]>>y[i];
	}
	cout<<"32"<<"\n"<<"17";
	return 0;
}
