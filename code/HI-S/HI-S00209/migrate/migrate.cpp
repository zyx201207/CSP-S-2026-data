#include<bits/stdc++.h>
using namespace std;
long long ge;
long long c,t,n,d,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			ge=a[2]-a[1];
			ge=d/ge;
			if(ge<=1){
				printf("0\n");
			}else{
				printf("%lld\n",max((long long)0,n-ge-ge+1));
			}
		}
	}
	
	
	return 0;
}
