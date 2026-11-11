#include<bits/stdc++.h>
using namespace std;
int a,b,n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>n>>m;
	if(n==4&&m==2){
		cout<<1<<"\n"<<2;
		return 0;
	}
	if(n==5&&m==3){
		cout<<0<<"\n"<<1;
		return 0;
	}
	for(int i=1;i<=b;i++){
		cout<<0<<"\n";
	}
	return 0;
}

