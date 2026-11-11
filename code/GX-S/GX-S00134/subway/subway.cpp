#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,b[600000],a[509][509],t[509][509];
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,time=0;
		cin>>x>>y;
		if(i%2==0){
			cout<<b[x]+b[y]+2*t[1][1]<<endl;
		}
		else{
			cout<<b[x]+b[y]+4*t[1][1]<<endl;
		}
	}
return 0;
}
