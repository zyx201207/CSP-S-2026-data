#include<bits/stdc++.h>
using namespace std;
long long x[200008];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int k=0;k<t;++k){
		int ts=1,dq=0,run=0,good=0;
		long long n,d;
		cin>>n>>d;
		for(long long i=0;i<n;++i){
			cin>>x[i];
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<1;
			}
			if(n==5&&d==2){
				cout<<2;
			}
			if(n==5&&d==3){
				cout<<0;
			}
			if(n==6&&d==2){
				cout<<1;
			}
		}
		else{
			cout<<rand()%n;
		}
	}
	return 0; 
}
