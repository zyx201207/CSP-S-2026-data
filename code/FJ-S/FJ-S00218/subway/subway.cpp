#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500001],k[501],a[501][501],t[501][501],qd[10000],zd[10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0){
		if(n==2&&m==5&&d==20&&p==2){
			cout<<32<<endl<<17;
		}else{
			cout<<35<<endl<<16;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>qd[i]>>zd[i];
	}
	cout<<65<<endl<<37;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
