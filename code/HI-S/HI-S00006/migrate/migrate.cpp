#include<bits/stdc++.h>
using namespace std;
int c,T;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=1){
			cout<<0<<'\n';
			continue;
		}
		long long ld=a[2]-a[1];
		ld=d/ld;
		if(ld<=1){
			cout<<0<<'\n';
			continue;
		}
		cout<<max(n-ld-ld+1,0LL)<<'\n';
	}
	return 0;
}
