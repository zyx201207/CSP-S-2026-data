#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se 
int n,m,a[500005],cnt[300005],lst[300005];
int t[500005],lazy[2000005];
void pd(int x){
	lazy[x<<1]+=lazy[x];
	lazy[1|x<<1]+=lazy[x];
	lazy[x]=0;
}
void upd(int x,int l,int r,int ll,int rr,int c){
	if(ll<=l&&r<=rr){
		lazy[x]+=c;
		return;
	}
	pd(x);
	int mid=(l+r)>>1;
	if(mid>=ll)upd(x<<1,l,mid,ll,rr,c);
	if(mid<rr)upd(1|x<<1,mid+1,r,ll,rr,c);
}
void qu(int x,int l,int r,int q){
	if(l==r){
		t[l]=lazy[x];
		return;
	}
	pd(x);
	int mid=(l+r)>>1;
	if(mid>=q)qu(x<<1,l,mid,q);
	if(mid<q)qu(1|x<<1,mid+1,r,q);
}
void qq(int x,int l,int r){
	if(l==r){
		t[l]=lazy[x];
		return;
	}
	pd(x);
	int mid=(l+r)>>1;
	qq(x<<1,l,mid);
	qq(1|x<<1,mid+1,r);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		qu(1,1,n,i);
		if(lst[a[i]]==i)continue;
		upd(1,1,n,i,lst[a[i]]-1,i-t[i]);
	}
	qq(1,1,n);
	for(int i=1;i<=n;i++){
		cnt[a[i]]=max(cnt[a[i]],i-t[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
