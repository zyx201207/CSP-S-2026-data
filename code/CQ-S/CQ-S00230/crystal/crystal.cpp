#include<bits/stdc++.h>
const int N=(1<<24);
#define ll long long
using namespace std;
ll n,m,l,r,wz,ans,a[500005];
struct node{
	ll he,ly;
}shu[N];
void xf(ll i,ll l,ll r){
	ll mid=(l+r)/2;
	if(shu[i].ly){
		shu[i*2].he+=(mid-l+1)*shu[i].ly;
		shu[i*2].ly+=shu[i].ly;
		shu[i*2+1].he+=(r-mid)*shu[i].ly;
		shu[i*2+1].ly+=shu[i].ly;
		shu[i].ly=0;
	}
} 
void add(ll i,ll l,ll r,ll ql,ll qr,ll d){
	if(ql<=l&&qr>=r){
		shu[i].he+=(r-l+1)*d;
		shu[i].ly+=d;
		return;
	}
	ll mid=(l+r)/2;
	xf(i,l,r);
	if(qr<=mid){
		add(i*2,l,mid,ql,qr,d);
		shu[i].he=shu[i*2].he+shu[i*2+1].he;
		return;
	}
	if(ql>mid){
		add(i*2+1,mid+1,r,ql,qr,d);
		shu[i].he=shu[i*2].he+shu[i*2+1].he;
		return;
	}
	add(i*2,l,mid,ql,qr,d);
	add(i*2+1,mid+1,r,ql,qr,d);
	shu[i].he=shu[i*2].he+shu[i*2+1].he;
}
int get(ll i,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&qr>=r) return shu[i].he;
	int mid=(l+r)/2;
	xf(i,l,r);
	if(qr<=mid) return get(i*2,l,mid,ql,qr);
	if(ql>mid) return get(i*2+1,mid+1,r,ql,qr);
	return get(i*2,l,mid,ql,qr)+get(i*2+1,mid+1,r,ql,qr);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		l=1,r=i;
		if(i>1) add(1,1,n,1,i-1,a[i]-a[i-1]);
		while(l<=r){
			int mid=(l+r)/2;
			if(get(1,1,n,mid,i)<=m) r=mid-1,wz=mid;
			else l=mid+1;
		}
		ans=max(ans,i-wz+1);
	}
	cout<<ans;
	return 0;
}
