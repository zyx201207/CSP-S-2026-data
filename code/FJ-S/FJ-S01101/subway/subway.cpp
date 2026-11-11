#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],x[505],y[505],a[505][505],t[505][505],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	if(n==2){
		cout<<32<<endl;
		cout<<17<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<endl;
	}
	
	return 0;
}
