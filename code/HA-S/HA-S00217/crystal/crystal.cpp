#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],t[N<<2],lazy[N<<2],num;
bool flag=0;
int ans=0;
ll read(){
	ll x=0,y=1;char ch;
	while((ch=getchar())<'0' || ch>'9') if(ch=='-') y=-1;
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}
void pushup(int k){
	t[k]=t[k<<1]+t[k<<1|1];
}
void pushdown(int k,int l,int r,int mid){
	ll x=lazy[k];
	t[k<<1]+=x*(mid-l+1);
	t[k<<1|1]+=x*(r-mid);
	lazy[k<<1]+=x;
	lazy[k<<1|1]+=x;
	lazy[k]=0;
}
void build(int k,int l,int r){
	t[k]=lazy[k]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,ll v){
	if(x<=l && r<=y){
		t[k]+=v*(r-l+1);
		lazy[k]+=v;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if(x<=mid) change(k<<1,l,mid,x,y,v);
	if(mid<y) change(k<<1|1,mid+1,r,x,y,v);
	pushup(k);
}
void query(int k,int l,int r,int x,bool v){
	if(v==1){
		if(l==r){
			if(num>=t[k]){
				num-=t[k];
				ans+=1;
			}
			return;
		}
		int mid=l+r>>1;
		pushdown(k,l,r,mid);
		if(x<=mid){
			query(k<<1,l,mid,x,1);
		}
		else{
			query(k<<1|1,mid+1,r,x,1);
			if(flag==1) return;
			query(k<<1,l,mid,x,0);
		}
	}
	else{
		if(num>=t[k]){
			num-=t[k];
			ans+=(r-l+1);
			return;
		}
		if(l==r){
			flag=1;
			return;
		}
		int mid=l+r>>1;
		pushdown(k,l,r,mid);
		if(num>=t[k<<1|1]){
			query(k<<1|1,mid+1,r,x,0);
			if(flag==1) return;
			query(k<<1,l,mid,x,0);
		}
		else{
			query(k<<1|1,mid+1,r,x,0);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	memset(t,0,sizeof(t));
	int true_ans=1;
	for(int i=2;i<=n;i++){
		flag=0;
		ans=0;
		num=m;
		change(1,1,n,1,i-1,a[i]-a[i-1]);
		query(1,1,n,i,1);
		true_ans=max(true_ans,ans);
	}
	cout<<true_ans;
}
