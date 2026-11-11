#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
map<long long,long long> x;
long long cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>m;
		if(n<=0){
			cout<<0<<endl;
			continue;
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(n==2){
			cout<<0<<endl;
			continue;
		}
		if(n==3){
			cout<<0<<endl;
			continue;
		}
		if(m==1){
			cout<<0<<endl;
			continue;
		}
		long long l=n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i-1]+m<x[i]){
				l--;
			}
		}
		if(l<=0){
			cout<<0<<endl;
			continue;
		}
		if(l==1){
			cout<<0<<endl;
			continue;
		}
		if(l==2){
			cout<<0<<endl;
			continue;
		}
		if(l==3){
			cout<<0<<endl;
			continue;
		}
		if(m==1){
			cout<<0<<endl;
			continue;
		}
		if(l-(2*m)+1<0){
			cout<<0<<endl;
		}else{
			cout<<l-(2*m)+1<<endl;
		}
	}
	return 0;
}
