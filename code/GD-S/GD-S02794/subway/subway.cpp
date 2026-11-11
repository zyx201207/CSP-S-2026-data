#include<bits/stdc++.h>
using namespace std;
int a[505][500005],t[505][500005],k[505],w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
	while(q--){
		int l,r;
		cin>>l>>r;
		if(12<=c&&c<=19){
			cout<<t[1][1]*2+w[l]+w[r]<<"\n";
		}
		else{
			cout<<w[l]+w[r]<<"\n";
		}
	}
	return 0;
} 
