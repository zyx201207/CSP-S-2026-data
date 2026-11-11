#include<iostream>
using namespace std;
int w[200005];
int k[1000];
int a[600][600],t[505][500000];
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;i<2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}	
		
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
}
