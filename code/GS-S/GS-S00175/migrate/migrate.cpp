#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d<x[2]-x[1]){
			cout<<0;
			return 0;
		}else if(d==x[2]-x[1]){
			cout<<n*(n-1)/2;
			return 0;
		}
	}
	return 0;
} 
