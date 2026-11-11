#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ff[N];
struct xds{
	int l,r,sum,laz;
}tr[N<<2];
inline void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r,tr[u].sum=0,tr[u].laz=0;
	if(l==r)return;
	int md=(l+r)>>1;
	build(u<<1,l,md),build(u<<1|1,md+1,r);
}
inline void down(int u){
	if(!tr[u].laz)return;
	tr[u<<1].sum=1;
	tr[u<<1].laz=1;
	tr[u<<1|1].sum=1;
	tr[u<<1|1].laz=1;
	tr[u].laz=0;
}
inline void xg(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].sum=1;tr[u].laz=1;
		return;
	}
	down(u);
	int md=(tr[u].l+tr[u].r)>>1;
	if(l<=md)xg(u<<1,l,r);
	if(md<r)xg(u<<1|1,l,r);
}
inline int q(int u,int x){
	while(tr[u].l!=tr[u].r){
		down(u);
		int md=(tr[u].l+tr[u].r)>>1;
		if(x<=md)u=(u<<1);
		else u=((u<<1)|1);
	}
	return tr[u].sum;
}
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1])f=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout << cnt[i] << ' ';
		return 0;
	}
	build(1,1,n);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=ff[a[j]];
				if(x&&!q(1,x)){
					xg(1,x,j-1);
				}
				ff[a[j]]=j;
			}
			for(int j=i;j<=n;j++){
				cnt[a[j]]+=(1-q(1,j));
				ff[a[j]]=0;
			}
			build(1,1,n);
		}
		for(int i=1;i<=m;i++)cout << cnt[i] << ' ';
		return 0;
	}
	return 0;
}