#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010];
bool check(ll mid){
	//1 2 4 4 4 4 4 4 4 
	ll cnt=0;
	for(int i=1;i<=mid;i++){
		cnt+=a[mid]-a[i];
	}
	return cnt<=m;
}
//22:30-----14:30
//2:30---18:30
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			int i=mid;
			while(i<=n&&a[i]==a[mid]){
				i++;
			}
			ans=i-1;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
