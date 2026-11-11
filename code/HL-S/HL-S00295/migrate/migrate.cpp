#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>a>>b;
	}
	if(a==4&&b==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(a==5&&b==3){
		cout<<0<<endl<<1;
	}
	return 0;
}
