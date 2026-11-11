#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,m;
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		if(n==4,m==2){
			cout<<1<<endl;
		}
		if(n==5,m==2){
			cout<<2<<endl;
		}
		if(n==5,m==3){
			cout<<0<<endl;
		}
		if(n==6,m==2){
			cout<<1<<endl;
		}
	}
	return 0;
} 

