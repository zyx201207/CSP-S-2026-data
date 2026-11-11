#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],las[300005],ne[500005];
struct node{
	int val[4000005],tag[4000005];
	bool bl[4000005];
	void pd(int ind){
		if(bl[ind]){
			bl[ind*2]=true;
			bl[ind*2+1]=true;
			tag[ind*2]+=tag[ind];
			tag[ind*2+1]+=tag[ind];
			bl[ind]=false;
			tag[ind]=0;
		}
		return;
	}
	void build(int ind,int l,int r){
		bl[ind]=false;
		val[ind]=0;
		tag[ind]=0;
		if(l==r){
			return;
		}
		int mid=(l+r)/2;
		build(ind*2,l,mid);
		build(ind*2+1,mid+1,r);
		return;
	}
	void add(int ind,int l,int r,int ll,int rr,int v){
		if(ll<=l&&r<=rr){
			bl[ind]=true;
			tag[ind]+=v;
			return;
		}
		pd(ind);
		int mid=(l+r)/2;
		if(ll<=mid){
			add(ind*2,l,mid,ll,rr,v);
		}
		if(rr>mid){
			add(ind*2+1,mid+1,r,ll,rr,v);
		}
		return;
	}
	int ask(int ind,int l,int r,int pos){
		if(l==r){
			if(bl[ind]){
				val[ind]+=tag[ind];
				tag[ind]=0;
				bl[ind]=false;
			}
			return val[ind];
		} 
		pd(ind);
		int mid=(l+r)/2;
		if(pos<=mid){
			return ask(ind*2,l,mid,pos);
		} 
		return ask(ind*2+1,mid+1,r,pos);
	}
}xds;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	xds.build(1,1,n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xds.add(1,1,n,i,n,1);
		if(las[a[i]]!=0){
			ne[las[a[i]]]=i;
		}
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(ne[i]!=0){
			xds.add(1,1,n,i+1,ne[i]-1,0-xds.ask(1,1,n,i));
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<xds.ask(1,1,n,las[i])<<' ';
	}
	return 0;
}
