#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005],prep[500005],diff[500005];
ll n,m;
bool check(ll x){//要用x个水晶合成 次数不能超过m 
	ll dif=a[x]*x-prep[x];
	if(dif>m) return 0;
	return 1; 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	cin>>n>>m;
	if(m>1e8){//m>1e8
		for(int i=1;i<=n;i++) cin>>a[i];
		ll dt=a[2]-a[1];
		
		
		for(int i=1;i<=n;i++){
			diff[i]=diff[i-1]+dt*i;
		}
		
		cout<<lower_bound(diff+1,diff+n+1,m+1)-diff-1+1;//diff下标从0开始对应 

//		ll l=1,r=n,ans=1;
//		while(l<=r){
//			ll mid=(l+r)/2;
//			if(diff[mid]<=m){
//				ans=mid;
//				l=mid+1;
//			}
//			else r=mid-1;
//		}
//		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) prep[i]=prep[i-1]+a[i];

	ll l=1,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans; 
	return 0;
}
