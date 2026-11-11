#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,ans;
long long a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(d<=(abs(a[2]-a[1]))){
			cout<<0<<"\n";
			continue;
		}
		ans=abs((d/abs(a[2]-a[1])-1)*(n-3));
		printf("%lld\n",abs(ans));
	}
	return 0;
}
