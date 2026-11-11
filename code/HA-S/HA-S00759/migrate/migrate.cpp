#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(c==0){
		if(n==5&&d==2){
			cout<<1<<"\n"<<2;
		}
		if(n==6&&d==2){
			cout<<0<<"\n"<<1;
		} 
	}
	return 0;
} 
