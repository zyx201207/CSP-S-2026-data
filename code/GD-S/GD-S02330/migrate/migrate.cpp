#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,d,a[2000001],y,s,v,g;
void dfs(ll u,ll k){
	if(u==y){
		if(s>k) s=k,v=0;
		if(s==k) v++;
		return;
	}
	for(ll i=u+1;i<=y;i++){
		if(abs(a[i]-a[x])<=d) dfs(i,k+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",a+i);
		for(ll i=1;i<n;i++) for(ll j=i+1;j<=n;j++){
			s=9e18,v=g=0;
			y=j;
			dfs(i,0);
			if(v==2) g++;
		}
		printf("%lld\n",g);
	}
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
