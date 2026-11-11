#include<bits/stdc++.h>
#define ll long long
#define Furinas return
#define Tears 0
#define Arias 1
#define N 500005
#define ls x<<1
#define rs x<<1|1
using namespace std;
ll n,m,a[N],ans,sum;
struct Tree{
	ll data,mi,lz;
}t[N<<2];
void pushup(ll x){
	t[x].data=t[ls].data+t[rs].data;
}
void pushdown(ll x,ll l,ll r){
	if(!t[x].lz) Furinas;
	ll mid=(l+r)/2;
	t[ls].data+=(mid-l+1)*t[x].lz;
	t[rs].data+=(r-mid)*t[x].lz;
	t[ls].lz+=t[x].lz;
	t[rs].lz+=t[x].lz;
	t[x].lz=0;
}
void update(ll x,ll l,ll r,ll L,ll R,ll v){
	if(l>R||r<L) Furinas;
	if(L<=l&&r<=R){
		t[x].data+=(r-l+1)*v;
		t[x].lz+=v;
		Furinas;
	} 
	ll mid=(l+r)/2;
	if(L<=mid) update(ls,l,mid,L,R,v);
	if(R>mid) update(rs,mid+1,r,L,R,v);
	pushup(x);
}
ll query(ll x,ll l,ll r,ll d){
	if(l==r){
		Furinas l;
	}
	ll mid=(l+r)/2;
	pushdown(x,l,r);
	sum+=t[rs].data;
	if(m>=sum+a[d]-a[mid]) Furinas query(ls,l,mid,d);
	else{
		sum-=t[rs].data;
		Furinas query(rs,mid+1,r,d);	
	}
}
void chk(ll x,ll l,ll r){
	if(l==r) Furinas;
	ll mid=(l+r)/2;
	chk(ls,l,mid);
	chk(rs,mid+1,r);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(Tears);
	cin.tie(Tears);cout.tie(Tears);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=0;
		ll op=query(1,1,n,i);
		ans=max(ans,i-op+1);
		if(i<n) update(1,1,n,1,i,a[i+1]-a[i]);
	}
	cout<<ans;
	Furinas Tears;
}
/*
题目要求n个数 经历m次对一个数进行加1操作后使得相同的水晶更多
自然想到排序 然后枚举右端点 看左边最多能够有多少个数等于他
首先在循环的时候维护一个数组g
然后枚举到i的时候 gj表示j~i的所有数都变成ai所需要的代价
然后二分即可
gj如何动态维护
从i->i+1
gj=a(i+1)-a(i)
前面的所有数都有共同的偏移量a(i+1)-ai
这个貌似可以用线段树来做
给前面的所有数都加上a(i+1)-ai 然后query的话代替了二分的作用
线段树内部维护啥
维护min值？
然后再query? 好像可以
先写着吧 
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
还要维护t[x].data 不用mi 
*/
