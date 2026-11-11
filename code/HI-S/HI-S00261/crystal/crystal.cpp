#include<bits/stdc++.h>
#define ll long long
#define l int
using namespace std;
l MAX_L=214748347;
ll n,m;
ll a[500010];
ll base;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		base+=a[i];
	}
	base=(base+m)/n;
	sort(a+1,a+n+1);
	ll left=1,right=n,avar=MAX_L,new_base=0,base_i=n/2;
	while(left<=right){
		ll mid=(left+right)/2;
		ll count=abs(a[mid]-base);
		if(avar>=count){
			avar=count;
			new_base=a[mid];
			base_i=mid;
		}
		if(a[mid]==base){
			new_base=base;
			base_i=mid;
			break;
		}else if(a[mid]>base){
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	base=new_base;
	ll ans=0;
	for(ll k=base_i;k>=1;k--){
		ll ans_count=1;
		ll m_count=m;
		for(ll i=k-1;i>=1;i--){
			if(a[k]-a[i]<=m_count){
				ans_count++;
				m_count=m_count-(a[k]-a[i]);
			}
		}
		ans=max(ans,ans_count);
	}
	cout<<ans;
	return 0;
}

