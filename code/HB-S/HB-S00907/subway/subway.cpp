#include<bits/stdc++.h>
using namespace;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,w[50010]={0},k[505],a[505][50010]={0},t[505][50010]={0},x[50010],y[50010],z[50050];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
		
	}
	return 0;
}
