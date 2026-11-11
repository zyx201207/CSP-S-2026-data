#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],tot,cnt[N],t[N],ans,sum[N],mul[N];
map<ll,ll> mp;
bool check(ll x,ll i){
	if((sum[i-1]-sum[x-1])*t[i]-(mul[i-1]-mul[x-1])<=m) return true;
	return false;
}
ll ef(ll l,ll r,ll pos){
	if(l>r) return l;
	ll mid=(l+r)>>1;
	if(check(mid,pos)) return ef(l,mid-1,pos);
	return ef(mid+1,r,pos);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!mp[a[i]]) mp[a[i]]=++tot;
		cnt[mp[a[i]]]++;
		t[mp[a[i]]]=a[i];
	}
	for(int i=1;i<=tot;i++){
		sum[i]=sum[i-1]+cnt[i];
		mul[i]=mul[i-1]+cnt[i]*t[i];
	}
	ans=cnt[1];
	for(int i=2;i<=tot;i++){
		ll left=m,res=cnt[i];
		ll x=ef(1,i-1,i);
		if(x!=i){
			left-=(sum[i-1]-sum[x-1])*t[i]-(mul[i-1]-mul[x-1]);
		    res+=sum[i-1]-sum[x-1];
		}
		if(x!=1){
			ll c=t[i]-t[x-1];
			res+=min(left/c,cnt[x-1]);
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
