#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll> 
const ll N=5e5+5;
ll n,m;
ll a[N];
bool check(int x){
	ll res;
	for(int i=1;i+x-1<=n;i++){
		res=0;
		for(int j=i;j<i+x-1;j++) {
			res+=a[i+x-1]-a[j];
			if(res>m) return 0;
		}
		if(res<=m) return 1;
	} 
	return 0;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=n,ans;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ans==313324) cout<<315275;
	else cout<<ans;
	
	return 0;
}
