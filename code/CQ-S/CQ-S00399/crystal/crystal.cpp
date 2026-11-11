#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int d[2000005],lazy[2000005],siz[2000005],ans;
void pushup(int p){
	d[p]=d[p<<1]+d[p<<1|1];
	siz[p]=siz[p<<1]+siz[p<<1|1];
}
void build(int p,int s,int t){
	if(s==t){
		siz[p]=1;
		return;
	}
	int mid=(s+t)>>1;
	build(p<<1,s,mid);
	build(p<<1|1,mid+1,t);
	pushup(p);
}
void pushdown(int p){
	if(lazy[p]){
		d[p<<1]+=siz[p<<1]*lazy[p],d[p<<1|1]+=siz[p<<1|1]*lazy[p];
		lazy[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
}
void change(int p,int s,int t,int l,int r,int c){
	if(l<=s&&t<=r){
		d[p]+=c*siz[p];
		lazy[p]+=c;
		return;
	}
	pushdown(p);
	int mid=(s+t)>>1;
	if(l<=mid)change(p<<1,s,mid,l,r,c);
	if(r>mid)change(p<<1|1,mid+1,t,l,r,c);
	pushup(p);
}
int query(int p,int s,int t,int x){
	if(s==t)return s;
	pushdown(p);
	int mid=(s+t)>>1;
	if(d[p<<1]<=x)return query(p<<1|1,mid+1,t,x-d[p<<1]);
	return query(p<<1,s,mid,x);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i=-~i)cin>>a[i];
	sort(a+1,a+n+1);
	build(1,1,n);
	for(int i=2;i<=n;i=-~i){
		change(1,1,n,n-i+1,n,a[i]-a[i-1]);
		int id=query(1,1,n,m);
		ans=max(ans,id-(n-i));
	}
	cout<<ans;
	return 0;
}
/*
rp++
*/
/*
100+100+32+20=252
怎么办，绝对没到一等！！！
挂分就可不可能了！！！
NO！！！ 
T3可能可以多上8分，但我不清楚时复对不对，理论上会卡到O(n^2)
博一把吧
不要让这个赛季成为我的最后一个赛季啊！！！ 
*/
