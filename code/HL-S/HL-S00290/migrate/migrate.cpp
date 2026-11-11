#include<bits/stdc++.h>
using namespace std;
int a[i];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	for(inr i=1; i<=n; i++){
		cin>>a[i];
	}if(n<=9){
		cout<<c;
	}else if(n<=300){
		cout<<t;
	}else if(n<=5000){
		cout<<n;
	}else{
		cout<<d;
	}
	return 0;
}
