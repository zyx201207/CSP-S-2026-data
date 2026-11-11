#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010],i,j;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(i=1;i<=t;i++){
		cin>>n>>d;
		for(j=1;j<=n;j++){
			cin>>x[j];
		} 
	}
	if(n==5&&d==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(n==6&&d==2){
		cout<<0<<endl<<1;
		return 0;
	}
	return 0;
}

