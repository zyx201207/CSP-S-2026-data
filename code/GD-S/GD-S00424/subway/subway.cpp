#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int d=0;d<c;d++){
		int w[m+1],k[n+2],x[q+1],y[q+1];
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		int a[n+2][n+2],t[n+2][n+2];
		for(int i=1;i<=n+2;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
		}
		 
	}
	return 0;
}
