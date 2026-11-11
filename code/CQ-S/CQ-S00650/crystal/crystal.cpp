#include<bits/stdc++.h>
#define ll long long
#define ls (u<<1)
#define rs (u<<1|1)
using namespace std;
const int N=5e5+5;
int n,ans=1;
ll a[N],m;
ll sum[N<<2],add[N<<2];
inline void pushup(int u){sum[u]=sum[ls]+sum[rs];}
inline void build(int u,int l,int r){
	if(l==r){sum[u]=a[n]-a[n-l+1];return;}
	int mid=(l+r)>>1;
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(u);
}
inline void apply(int u,int l,int r,ll v){
	sum[u]+=1LL*(r-l+1)*v;add[u]+=v;
}
inline void pushdown(int u,int l,int r){
	int mid=(l+r)>>1;
	if(add[u]!=0){
		apply(ls,l,mid,add[u]),apply(rs,mid+1,r,add[u]);
		add[u]=0;
	}
}
inline void update(int u,int l,int r,int tl,int tr,ll v){
	if(tl<=l&&r<=tr){apply(u,l,r,v);return;}
	pushdown(u,l,r);
	int mid=(l+r)>>1;
	if(tl<=mid)update(ls,l,mid,tl,tr,v);
	if(tr>mid)update(rs,mid+1,r,tl,tr,v);
	pushup(u);
}
inline int query(int u,int l,int r,ll v){
	if(l==r)return l+(sum[u]<=v?0:-1);
	pushdown(u,l,r);
	int mid=(l+r)>>1;
	if(sum[ls]<=v)return query(rs,mid+1,r,v-sum[ls]);
	else return query(ls,l,mid,v);
}
inline void print(int u,int l,int r){
	if(l==r){cout<<sum[u]<<" ";return;}
	int mid=(l+r)>>1;
	print(ls,l,mid),print(rs,mid+1,r);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    build(1,1,n);
	a[n+1]=a[n];
    for(int i=n;i>=1;i--){
    	update(1,1,n,n-i+1,n,a[i]-a[i+1]);
    	ans=max(ans,query(1,1,n,m)-(n-i));
	}
	cout<<ans<<"\n";
    return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/
//落魄谷中寒风吹，春秋蝉鸣少年归。荡魂山上石人泪，定仙游走魔向北。
//逆流河上众仙退，爱情不敌坚持泪。宿命天成命中败，仙尊悔二我不悔！