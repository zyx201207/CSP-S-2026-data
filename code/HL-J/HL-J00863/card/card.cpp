#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500009];
ll p[300009];
ll nxt[500009];
ll ans[300009];
bitset<300009>bit;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		nxt[p[a[i]]]=i;
		p[a[i]]=i;
		nxt[p[a[i]]]=i;
	}
	for(ll i=1;i<=n;i++){
		bit.set();
		for(ll j=i;j<=n;){
			ans[a[j]]+=bit[a[j]];
			bit[a[j]]=0;
			while(nxt[j]!=j) j=nxt[j];
			j++;
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
/*

*/