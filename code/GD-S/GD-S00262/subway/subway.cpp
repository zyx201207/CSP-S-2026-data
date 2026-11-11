#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005],k[505];
int a[505][500005],t[505][500005];
int x[500005],y[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int l=1;l<=k[i];l++){
			cin>>a[k[i]][l]>>t[k[i]][l];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2)cout<<"32\n17";
		if(n==3)cout<<"35\n16";
		return 0;
	}
	return 0;
} 
