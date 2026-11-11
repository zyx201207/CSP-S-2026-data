#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		unsigned long long n,d;
		cin>>n>>d;
		unsigned long long x[n+5];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int aaa=0;
		for(int i=1;i<=n-1;i++){
			if((x[i+1]-x[i])!=(x[2]-x[1])){
				aaa=1;
			}
		}
		if(n<=3){
			cout<<0<<endl;
		}
		else if(n==4){
			if(d>=(x[2]-x[1])&&d<=(x[3]-x[1])&&d>=(x[3]-x[2])&&d>=(x[4]-x[3])){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else if(aaa==0){
			if(d>=(x[2]-x[1])&&d<=(x[3]-x[1])&&d>=(x[3]-x[2])&&d>=(x[4]-x[3])){
				cout<<n-3<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
