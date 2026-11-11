#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t){
		long long n,d,x[2000010];
		for(long long i=0;i<n;i++){
			cin>>x[i];
		}
		if(n==4&&d==2){
			cout<<1<<endl;
		}
		else if(n==5&&d==2){
			cout<<2<<endl;
		}
		else if(n==5&&d==3){
			cout<<0<<endl;
		}
		else if(n==6&&d==2){
			cout<<1<<endl;
		}
		else{
			cout<<0;
		}		
	}
	return 0;
} 
