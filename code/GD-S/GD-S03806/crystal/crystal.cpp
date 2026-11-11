//edit by gitxiaozheng
#include<bits/stdc++.h>
using namespace std;
#define L long long
#define qcin(a) cin>>a
#define qcout(a) cout<<a
#define space cout<<' '
#define enter cout<<'\n'

const int maxn=5e5+10;
struct Node{
	L val,lztag;
}segt[maxn*4]; 
int ls(int p){
	return p<<1;
}
int rs(int p){
	return p<<1|1;
}
void psup(int p){
	segt[p].val=segt[ls(p)].val+segt[rs(p)].val;	
}
void addtag(int p,int l,int r,L k){
	segt[p].lztag+=k;
	segt[p].val+=1ll*(r-l+1ll)*k;
}
void psdown(int p,int l,int r){
	int mid=(l+r)>>1;
	addtag(ls(p),l,mid,segt[p].lztag);
	addtag(rs(p),mid+1,r,segt[p].lztag);
	segt[p].lztag=0;
}
void upd(int l,int r,int tl,int tr,int p,L k){
	if(l<=tl&&tr<=r){
		addtag(p,tl,tr,k);
		return;
	}
	psdown(p,tl,tr);
	int mid=(tl+tr)>>1;
	if(l<=mid){
		upd(l,r,tl,mid,ls(p),k);
	}
	if(r>mid){
		upd(l,r,mid+1,tr,rs(p),k);
	}
	psup(p);
}
L query(int l,int r,int tl,int tr,int p){
	if(l<=tl&&tr<=r){
		return segt[p].val;
	}
	psdown(p,tl,tr);
	int mid=(tl+tr)>>1;
	L res=0;
	if(l<=mid){
		res+=query(l,r,tl,mid,ls(p));
	}
	if(r>mid){
		res+=query(l,r,mid+1,tr,rs(p));
	}
	return res;
}
L A[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	L m,mm=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(A[i]);
	}
	sort(A+1,A+1+n);
	int ans=0;
	int i=1,l=1;
	for(i=2;i<=n;i++){
		if(A[i]!=A[i-1]){			
			upd(l,i-1,1,n,1,A[i]-A[i-1]);
			mm=query(l,i-1,1,n,1);
			if(mm>m){
				ans=max(ans,i-l);
				int ll=l,rr=i;
				int wl=0;
				while(ll<=rr){
					int mid=(ll+rr)>>1;
					if(mm-query(l,mid,1,n,1)<=m){
						wl=mid;
						rr=mid-1;
					}else{
						ll=mid+1;
					}
				}
				l=wl+1;
			}
		}
	}
	cout<<(max(ans,i-l));
	return 0;
} 
//8 27
//-3 -1 2 2 7 7 7 7
