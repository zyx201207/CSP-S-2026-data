#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,u,v;
long long a[5005][5005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&u,&v);
			a[u][v]=1;
			a[v][u]=1;
		}
	}
	return 0;
}
