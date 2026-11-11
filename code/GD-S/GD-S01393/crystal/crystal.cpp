#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500001],sum[2000001],la[2000001],m;
void build(int u,int l,int r){
	if(l==r){sum[u]=a[l];return ;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	sum[u]=sum[u<<1]+sum[u<<1|1]; 
}
void down(int u,int l,int r){
	int mid=(l+r)>>1;
	sum[u<<1]+=(mid-l+1)*la[u];
	sum[u<<1|1]+=(r-mid)*la[u];
	la[u<<1]+=la[u],la[u<<1|1]+=la[u];
	la[u]=0;
}
int qry(int u,int l,int r,int x,int y){
	if(l>=x&&r<=y)return sum[u];
	int mid=(l+r)>>1,res=0;
	if(la[u])down(u,l,r);
	if(x<=mid)res+=qry(u<<1,l,mid,x,y);
	if(y>mid)res+=qry(u<<1|1,mid+1,r,x,y);
	return res;
}
void update(int u,int l,int r,int x,int y,int c){
	if(l>=x&&r<=y){
		sum[u]+=(r-l+1)*c;
		la[u]+=c;
		return ;
	}
	int mid=(l+r)>>1;
	if(la[u])down(u,l,r);
	if(x<=mid)update(u<<1,l,mid,x,y,c);
	if(y>mid)update(u<<1|1,mid+1,r,x,y,c);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	build(1,1,n);int ans=1;
	for(int r=2;r<=n;r++){
		int l=0,rr=r;
		update(1,1,n,1,r-1,-a[r]);
		while(l+1<rr){
			int mid=(l+rr)>>1;
//			cout<<l<<","<<rr<<":"<<mid<<","<<r-1<<":"<<qry(1,1,n,mid,r-1)<<endl;
			if(qry(1,1,n,mid,r-1)+m<0){
				l=mid;
			}
			else rr=mid;
		}
		if(l+1==r)continue;
		ans=max(ans,r-l);
		update(1,1,n,1,r-1,a[r]);
	}
	cout<<ans;
}
