#include<bits/stdc++.h>
using namespace std;
int n,sz[2000005],ls[2000005],rs[2000005],cnt,ans=1;
long long sum[2000005],lazy[2000005],a[500005],m,mm;
void update(int bh){
	if(lazy[bh]){
		if(ls[bh]&&rs[bh]){
			sum[ls[bh]]+=sz[ls[bh]]*lazy[bh];
			sum[rs[bh]]+=sz[rs[bh]]*lazy[bh];
			lazy[ls[bh]]+=lazy[bh];
			lazy[rs[bh]]+=lazy[bh];
		}
		lazy[bh]=0;
	}
	return;
}
void build(int bh,int l,int r,int x){
	if(l==r){
		sz[bh]=1;
		return;
	}
	update(bh);
	int mid=(l+r)/2;
	if(x<=mid){
		if(ls[bh]==0)ls[bh]=++cnt;
		build(ls[bh],l,mid,x);
	}
	else{
		if(rs[bh]==0)rs[bh]=++cnt;
		build(rs[bh],mid+1,r,x);
	}
	sum[bh]=sum[ls[bh]]+sum[rs[bh]];
	sz[bh]=sz[ls[bh]]+sz[rs[bh]];
	return;
}
void change(int bh,int l,int r,int gl,int gr,int x){
	if(gl<=l&&r<=gr){
		sum[bh]+=sz[bh]*x;
		lazy[bh]+=x;
		return;
	}
	update(bh);
	int mid=(l+r)/2;
	if(gr<=mid)change(ls[bh],l,mid,gl,gr,x);
	else if(gl>mid)change(rs[bh],mid+1,r,gl,gr,x);
	else change(ls[bh],l,mid,gl,gr,x),change(rs[bh],mid+1,r,gl,gr,x);
	sum[bh]=sum[ls[bh]]+sum[rs[bh]];
	return;
}
int ef(int bh,int l,int r,long long& lm){
	if(sum[bh]<=lm){
		lm-=sum[bh];
		return sz[bh];
	}
	if(l==r)return 0;
	update(bh);
	int rt=0;
	int mid=(l+r)/2;
	if(sum[rs[bh]]<=lm){
		lm-=sum[rs[bh]];
		rt+=sz[rs[bh]];
		rt+=ef(ls[bh],l,mid,lm);
	}
	else{
		rt+=ef(rs[bh],mid+1,r,lm);
	}
	return rt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	cin>>a[1];
	build(++cnt,1,n,1);
	for(int z=2;z<=n;z++){
		cin>>a[z];
		change(1,1,n,1,z,a[z]-a[z-1]);
		mm=m;
		ans=max(ans,ef(1,1,n,mm)+1);
		build(1,1,n,z);
	}
	cout<<ans;
	return 0;
}
