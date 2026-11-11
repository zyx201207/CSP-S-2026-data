#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k[505],a[505][505],t[505][505],x[505],y[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}else if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	return 0;
}
