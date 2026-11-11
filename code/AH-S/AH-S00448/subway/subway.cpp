#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000+10;
ll c,n,m,d,q;
ll w[N];
struct node{
	ll l1,l2;
}s[N];
bool mp[N][N];
ll a[N];
ll mi=0x3f3f3f3f;
void dfs(ll l,ll r,ll sum,ll lo){
	if(sum>mi) return ;
	if(l==r){
		 mi=min(mi,sum);
		 return ;
	}
	for(ll i=1;i<=m;i++){
		 if(mp[l][i]!=0) dfs(i,r,sum+s[l].l1+s[i].l1,mp[l][i]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) scanf("%lld",&s[i].l2);
	for(ll i=1;i<=n;i++){
		ll t;
		scanf("%lld",&t);
		for(ll j=1,x;j<=t;j++){
			 scanf("%lld%lld",&a[j],&x);
			 s[a[j]].l1=x;
		 }
		for(ll j=1;j<=t;j++) for(ll k=j+1;k<=t;k++) mp[a[i]][a[j]]=i;
	}
	while(q--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll sum=s[l].l2+s[r].l2;
		mi=0x3f3f3f3f;
		dfs(l,r,sum,1);
		printf("%lld\n",mi);
	}
	return 0;
}
