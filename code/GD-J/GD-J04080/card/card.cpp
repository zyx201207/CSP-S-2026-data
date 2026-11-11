#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e5+5,M=3e5+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
struct Tree1{
	int x;int val;
}tree1[N<<2];
struct Tree2{
	bool x,val;
}tree2[N<<2];
int a[N],b[N],last[M],ans[N];
void push_down1(int x){
	int ls=x<<1,rs=x<<1|1;
	tree1[ls].x=min(tree1[x].val,tree1[ls].x);
	tree1[rs].x=min(tree1[x].val,tree1[rs].x);
	tree1[ls].val=min(tree1[x].val,tree1[ls].val);
	tree1[rs].val=min(tree1[x].val,tree1[rs].val);
	tree1[x].val=2e9;
	return ;
}
void build(int x,int l,int r){
	tree1[x].x=tree1[x].val=2e9;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	return ;
}
void change1(int x,int l,int r,int L,int R,int c){
	if(L<=l&&r<=R){
		tree1[x].x=min(tree1[x].x,c);
		tree1[x].val=min(tree1[x].val,c);
		return ;
	}
	if(tree1[x].val!=2e9)push_down1(x);
	int mid=(l+r)>>1;
	if(L<=mid)change1(x<<1,l,mid,L,R,c);
	if(mid<R)change1(x<<1|1,mid+1,r,L,R,c);
	return ;
}
int ask1(int x,int l,int r,int k){
	if(l==r&&l==k)return tree1[x].x;
	if(tree1[x].val!=2e9)push_down1(x);
	int mid=(l+r)>>1;
	if(k<=mid)return ask1(x<<1,l,mid,k);
	if(mid<k)return ask1(x<<1|1,mid+1,r,k);
}
void push_down2(int x){
	int ls=x<<1,rs=x<<1|1;
	tree2[ls].x=tree2[rs].x=tree2[x].val;
	tree2[x].val=0;
}
void change2(int x,int l,int r,int L,int R,int c){
	if(L>R)return ;
	if(L<=l&&r<=R){
		tree2[x].val=tree2[x].x=c;
		return ;
	}
	int mid=(l+r)>>1;
	if(tree2[x].val)push_down2(x);
	if(L<=mid)change2(x<<1,l,mid,L,R,c);
	if(mid<R)change2(x<<1|1,mid+1,r,L,R,c);
	return ;
}
int ask2(int x,int l,int r,int k){
	if(l==r&&l==k)return tree2[x].x;
	int mid=(l+r)>>1;
	if(tree2[x].val)push_down2(x);
	if(k<=mid)return ask2(x<<1,l,mid,k);
	if(mid<k)return ask2(x<<1|1,mid+1,r,k);
}
void solve(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
	for(int i=n;i>=1;i--){
		if(last[a[i]]==0||(!ask2(1,1,n,last[a[i]]))){
			last[a[i]]=i;
			b[i]=n-i+1;
			change2(1,1,n,i,i,1);
		}else{
			change2(1,1,n,i+1,last[a[i]]-1,0);
			change1(1,1,n,i+1,last[a[i]]-1,n-i+1);
		}
	}
	//cout<<ask2(1,1,n,5);
	for(int i=1;i<=n;i++){
		if(b[i]==0)continue;
		if(ask2(1,1,n,i)){
			ans[a[i]]+=n-b[i]+1;
		}else{
	//		cout<<ask1(1,1,n,i)<<' '<<b[i]<<' '<<i<<'\n';
			ans[a[i]]+=ask1(1,1,n,i)-b[i];
		}
	}
	for(int i=1;i<=m;i++){
		write(ans[i]);
		putchar(' ');
	}
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
