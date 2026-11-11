#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7,MX=1e18+1;
ll n,m;
ll a[N];
ll cnt1[N],cnt2[N];
ll sUm(int i,int j){
	if(cnt2[j]<0)return MX;
	return cnt2[j]-cnt2[i-1]-((cnt1[j]-cnt1[i-1])*(i-1));
}
bool ch(int x){
	for(int i=x;i<=n;i++){
		if(sUm(i-x+1,i)<=m){
			return 1;
		}
	}return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll t=1;
	//scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			cnt1[i]=a[i]-a[i-1];
		}for(int i=2;i<=n;i++){
			cnt2[i]=cnt1[i]*(i-1),cnt2[i]+=cnt2[i-1];
		}for(int i=1;i<=n;i++){
			cnt1[i]+=cnt1[i-1];
		}
		ll l=1,r=n,mid,ans=1;
		while(l<=r){
			mid=(l+r)>>1;
			if(ch(mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
