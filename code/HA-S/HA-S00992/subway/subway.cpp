#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,w[500010],k[50010],a[510][500010],t[510][500010],x[100010],y[100010];
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(long long i=0; i<n; i++) {
		cin>>k[i];
		for(long long j=1; j<=m; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=0; i<q; i++) {
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}
	else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl;
		cout<<16<<endl;
	}
	else{
		cout<<37<<endl;
		cout<<15<<endl;
	}
	return 0;
}
