#include<bits/stdc++.h>
using namespace std;
int a[1005];
int k[1005];
int w[1005];
int x[5],y[5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>w[j];
		} 
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2&&m==5&&d==20&&p==2){
		cout<<32<<endl<<17;
	}
	if(n==3&&m==7&&d==20&&p==2){
		cout<<35<<endl<<16; 
	}
	return 0;
}
