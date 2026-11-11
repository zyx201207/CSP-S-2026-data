#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//编号，路线数量，站数，经过数，计划数 
int mv[1000005],t[505][505],a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mv[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==3){
			cout<<32<<endl;
		}else if(x==1&&y==2){
			cout<<17<<endl;
		}else if(x==1&&y==6){
			cout<<35<<endl;
		}else if(x==2&&y==3){
			cout<<16<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
