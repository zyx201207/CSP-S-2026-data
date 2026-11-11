#include<bits/stdc++.h>
using namespace std;
long long k[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
		} 
		long long s=k[2]-k[1];
		if(n==1||d<2*s||d>k[n]-k[1]){
			cout<<0<<endl;
		}else{
			cout<<n-(d/s)*2+1<<endl;
		}
	}
	return 0;
}
