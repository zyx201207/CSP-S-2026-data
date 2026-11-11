#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(a[2]-a[1]>d){
			cout<<0<<'\n';
		}
		else{
			cout<<n-(d+1)<<'\n';
		}
	}
	return 0;//127
}//8fen
