#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N],c[N*4],tag[N*4];
int cnt,pos[N];
void puttag(int l,int r,int x,long long w){
	c[x]+=(r-l+1)*w;
	tag[x]+=w;
}
void pushdown(int l,int r,int x){
	if(tag[x]==0) return;
	int mid=(l+r)>>1;
	puttag(l,mid,x<<1,tag[x]);
	puttag(mid+1,r,x<<1|1,tag[x]);
	tag[x]=0;
}
void upd(int l,int r,int x,int ql,int qr,long long w){
	if(l>=ql && r<=qr){puttag(l,r,x,w);return;}
	pushdown(l,r,x);
	int mid=(l+r)>>1;
	if(mid>=ql) upd(l,mid,x<<1,ql,qr,w);
	if(mid<qr) upd(mid+1,r,x<<1|1,ql,qr,w);
	c[x]=c[x<<1]+c[x<<1|1];
}
int qry(int l,int r,int x,int y,long long w){
	if(w==0) return 0;
	if(l==r){
		if(w>=c[x]) return y-l+1;
		else return y-l;
	}
	pushdown(l,r,x);
	int mid=(l+r)>>1;
	if(c[x<<1|1]<w) return qry(l,mid,x<<1,y,w-c[x<<1|1]);
	else return qry(mid+1,r,x<<1|1,y,w);
	return 0; 
}
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
//	freopen("crystal3.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) pos[++cnt]=i-1;
	}
	pos[++cnt]=n;
	int ans=pos[cnt]-pos[cnt-1];
	for(int i=1;i<cnt;i++){
		ans=max(ans,pos[i]-pos[i-1]);
		upd(1,n,1,1,pos[i],a[pos[i]+1]-a[pos[i]]);
		ans=max(ans,qry(1,n,1,pos[i],m)+pos[i+1]-pos[i]);
	}
	cout<<ans;
	return 0;
}
//100
