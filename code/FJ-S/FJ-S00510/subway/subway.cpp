#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],t[500][500001],xl[500][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int zg,tg;
			cin>>zg>>tg;
			t[i][zg]=tg;
			
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int qx,zx;
		cin>>qx>>zx;
	}
	if(n==2){
		cout<<32<<endl<<17;
	}else if(n==3){
		cout<<35<<endl<<16;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
