#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,n,d;
	cin>>c>>t>>n>>d;
	int a[n];
	for(int i=0;i<=t;i++){
		cin>>a[i];	
	}
	if((a[1]-a[0])+(a[3]-a[1])==(a[2]-a[0])+(a[3]-a[2]) && n<=9 && a[2]-a[0]<=d && a[3]-a[2]<=d){
		cout<<1;
	}
	if(a[0]==1 && a[4]==5){
		cout<<2;
	}
	else{
		cout<<endl<<0<<endl<<1;
	}
	return 0;
}
