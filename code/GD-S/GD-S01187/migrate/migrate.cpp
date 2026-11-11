#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ll ans=0;
		scanf("%lld%lld",&n,&d); 
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(ll i=1;i<=n-3;i++){
			if(x[i+1]-x[i]<=d && x[i+2]-x[i]<=d && x[i+3]-x[i]>d && x[i+3]-x[i+1]<=d && x[i+3]-x[i+2]<=d){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
