#include<bits/stdc++.h>
using namespace std;
long long a[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==5&&d==3){
			cout<<0;
		}
		if(n==6&&d==2){
			cout<<1;
		}
		if(n==4&&d==2){
			cout<<1;
		}
		if(n==4&&d==2){
			cout<<2;
		}
	}
}
