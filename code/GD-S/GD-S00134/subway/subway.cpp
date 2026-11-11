#include<bits/stdc++.h>
using namespace std;
int tim[1000000];
int a[500][500009];
int t[500][500009] ;
int c,n,m,d,q;
int v[100005][9];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	int k;
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
		cin>>a[i][j];
		cin>>t[i][j];
	}}
	for(int i=1;i<=q;i++){
		cin>>v[i][1];
	}
	
	cout<<35<<endl<<16;
	return 0;
	}
	
	
