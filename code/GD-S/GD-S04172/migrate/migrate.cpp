#include <bits/stdc++.h>
using namespace std ;
const long long N =2e6+10;
long long c ,n, t,m;
long long k ;
long long a[N] , b[N];
int flag =1;
int  main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		
		for(long long i =1;i<=n;i++){
			cin>>a[i];
			if (i==2)k=a[2]-a[1];
			if(i>2 && a[i]-a[i-1] != k )flag =0;
		}
		
		if(flag){
			if(m/k<=1){
				cout<<0<<'\n';
				continue;
			}
			else {
				cout<<max(0ll,n-(m/k * 2 - 1))<<'\n';
				continue;
			}
		}
		else {
			cout<<0<<'\n';
			
		}	
}
