#include <bits/stdc++.h>

using namespace std;
const long long N=514114;
long long m,n,c,d,q,w[N],k,a[514][N],t[514][N];
long long pic[5141][5141];

int pf(){
	
	
}

int bx(){
	long long fr,to;
	cin>>fr>>to;
	
	return 0;
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(c>=7&&c<=11){
		//pianfenxiefa
		pf();
	}else{
		while(q--){
			bx();
		}
	}
	
	return 0;
}
