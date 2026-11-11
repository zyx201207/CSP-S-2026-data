#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000010],xx[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||12||0){
		while(t--){
			ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			ll xd=x[2]-x[1];
			ll m=d/xd;
			for(int i=2;i<=m;i++){
				if(i+i-1<=m+1&&i!=m||i+i-1>n){ 
					continue;
				}else{
					ans+=n-i-i+1;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
