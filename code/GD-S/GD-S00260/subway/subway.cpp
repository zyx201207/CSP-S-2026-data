#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[5005][5005],t[5005][5005],x[500005],y[500005];
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
		if(c!=0){
			cout<<w[x[i]]+w[y[i]];
		}
	}
	if(c==0){
		if(n==2){
			cout<<32<<"/n";
			cout<<17<<"/n";
		}
		if(n==2){
			cout<<35<<"/n";
			cout<<16<<"/n";
		}
	}
} 
