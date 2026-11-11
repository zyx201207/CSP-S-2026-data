#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long MAXN=500005;
ll n,mm,q[MAXN],w[MAXN];
int ans=1;
int ask(ll a){
	if(q[a]*a-w[a]<=mm) return 1;
	ll l=1,r=a-1,m;
	while(l<r){		
		m=(l+r)>>1;
		if(mm<q[a]*(a-m)-(w[a-1]-w[m-1])) l=m+1;
		else r=m;		
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&mm);
	for(int i=1;i<=n;i++){
		scanf("%lld",&q[i]);
	}
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		w[i]=w[i-1];
		w[i]+=q[i];		
	}
	for(int i=2;i<=n;i++){
		ans=max(ans,i-ask(i)+1);
	}
	printf("%lld",ans);

	
	
	return 0;
} 

