#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll; 
ll n,m,a[N];
bool check(int k){
	ll s=0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[k]) s+=a[k]-a[i];
	} 
	if(s<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	ll l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	} 
	while(a[ans]==a[ans+1]) ans++; 
	printf("%lld",ans);
	return 0;
}

