#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005],s[500005],q[500005];
inline ll check(ll L,ll R){
	return q[R]-((L-1)*a[R]-s[L-1]);
}
void pt45(){
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=1000000000000;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++)q[i]=q[i-1]+(a[i]-a[i-1])*(i-1);
	ll ans=1;
	for(ll R=1;R<=n;R++){
		for(ll L=1;L<=R;L++){
			if(check(L,R)<=m)ans=max(ans,R-L+1);
		}
	}
	printf("%d",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	if(n<=5000){
		pt45();
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=1000000000000;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++)q[i]=q[i-1]+(a[i]-a[i-1])*(i-1);
	ll ans=1;
	for(ll l=1,r=1;l<=n;l++){
		while(check(l,r)<=m){
			ans=max(ans,r-l+1);
			r++;
		}
	}
	printf("%d",ans);
	return 0;
}
