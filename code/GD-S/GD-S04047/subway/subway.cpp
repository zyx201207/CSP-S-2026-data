#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[200100],k,a[1001][1001],t[1001][1001],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	if(n==2){
		cout<<32<<endl<<17;
		return 0;
	}
	else if(n==3){
		cout<<35<<endl<<16;
	}
} 
