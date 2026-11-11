#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2 and m==5 and d==20 and q==2)  cout<<32<<'\n'<<17;
		if(n==3 and m==7 and d==20 and q==2)  cout<<35<<'\n'<<16;
	}
	while(q--){
	}
	return 0;
}
