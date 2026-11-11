#include<bits/stdc++.h>
using namespace std;
long long n,c,d,t,ca;
long long il[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		
		for(int i=1;i<=n/2;i++){
			scanf("%lld",&il[i]);
		}
		ca=abs(il[1]-il[2]);
		if(ca>=d&&0){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
} 
