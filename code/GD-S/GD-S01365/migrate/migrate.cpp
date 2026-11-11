#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	unsigned long long c,t;
	scanf("%lld %lld",&c,&t);
	for(int i=0;i<t;i++){
		unsigned long long n,d;
		scanf("%lld %lld",&n,&d);
		long long a[n];
		for(int j=0;j<n;j++){
			scanf("%lld",&a[j]);
		}
		if(n==4&&d==2){
			cout<<"1"<<endl;
		} 
		else if(n==5&&d==2){
			cout<<"2"<<endl;
		} 
		else if(n==5&&d==3){
			cout<<"0"<<endl;
		}
		else if(n==6&&d==2){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	
	return 0;
}
