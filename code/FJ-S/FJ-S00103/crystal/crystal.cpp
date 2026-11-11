#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500010],ans=0,m;
pair<ll,ll> check(ll mid){
	ll ls=0;
	ll cnt=0;
	ll final=upper_bound(a+1,a+n+1,mid)-a;
	for(int i=final;i>=1;i--){
		if(a[i]>mid) continue;
		ll d=mid-a[i];
		if(d<0) continue;
		ls+=d;
		cnt++;
	}
	if(ls<=m) return {cnt,1};
	ls=0,cnt=0;
	for(int i=final;i>=1;i--){
		if(a[i]>mid) continue;
		ll d=mid-a[i];
		if(d<0) continue;
		if(d+ls>m) return {cnt,0};
		else ls+=d,cnt++;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=a[1],r=a[n];
	if(r<=10000){
		for(int i=l;i<=r;i++) ans=max(ans,check(i).first);
		cout<<ans;
		return 0;
	}
	while(l<=r){
		int mid=(l+r)>>1;
		pair<ll,ll> res=check(mid);
		ans=max(ans,res.first);
		if(res.second==1) l=mid+1;
		else r=mid-1;
	}
	for(int i=l;i<=a[n];i++) ans=max(ans,check(i).first);
	cout<<ans;
	return 0;
}
