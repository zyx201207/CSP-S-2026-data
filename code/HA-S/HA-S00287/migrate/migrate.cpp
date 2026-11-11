/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
//多测不清空，保龄两行泪 
const int N=2e6+999;
int c,t;
int n;
ll d;
ll x[N];
ll maxx[N];
//io
void input(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)x[i]=read();
}
//init
void init(){
	for(int i=n,j=n;i>0;i--){
		while(x[j]-x[i]>d)j--;
		maxx[i]=j;
	}
}
//tree
ll dp[N];
struct tree{
	ll sum,lazy;
	int len;
}tr[N*4];
void build(int id,int l,int r){
	tr[id].len=(r-l+1);
	if(l==r)return;
	int mid=(l+r)>>1;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void pu(int id){
	tr[id].sum=tr[id*2].sum+tr[id*2+1].sum;
} 
void pd(int id){
	tr[id*2].sum+=tr[id*2].len*tr[id].lazy;
	tr[id*2+1].sum+=tr[id*2+1].len*tr[id].lazy;
	tr[id*2].lazy+=tr[id].lazy;
	tr[id*2+1].lazy+=tr[id].lazy;
	tr[id].lazy=0;
}
void add(int id,int l,int r,int ql,int qr,ll v){
	if(r<l)return;
	if(l>qr||ql>r)return;
	if(ql<=l&&r<=qr){
//		cout<<tr[id].len<<' '<<v<<' ';
//		cout<<tr[id].sum<<endl;
		tr[id].sum+=tr[id].len*v;
//		cout<<tr[id].sum<<endl;
//		cout<<l<<' '<<r<<endl;
		tr[id].lazy+=v;
		return;
	}
	pd(id);
	int mid=(l+r)>>1;
	add(id*2,l,mid,ql,qr,v),add(id*2+1,mid+1,r,ql,qr,v);
	pu(id);
}
ll query(int id,int l,int r,int pos){
	if(pos<l||r<pos)return 0;
	if(l==r){
//		cout<<pos<<' '<<l<<' '<<r<<endl;
		return tr[id].sum;
	}
	pd(id);
	int mid=(l+r)>>1;
	return query(id*2,l,mid,pos)+query(id*2+1,mid+1,r,pos);
}
void clear(int id,int l,int r){
	tr[id].sum=tr[id].lazy=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	clear(id*2,l,mid),clear(id*2+1,mid+1,r);
} 
//solve
ll ans;
void solve(int now){
//	cout<<now<<endl;
	for(int i=now;i<=n;i++)dp[i]=0;
	int top=maxx[now];
	for(int i=now+1;i<=top;i++)dp[i]=1;
	while(top!=now){
		for(int i=now+1;i<=top;i++){
			dp[i]=max(dp[i],query(1,1,n,i));
			ans+=(dp[i]==2);
			add(1,1,n,top+1,maxx[i],dp[i]);
		}
		now=top;
		top=maxx[top];
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i]<<' ';
//	}
//	cout<<endl;
	clear(1,1,n);
}
//clear
void clear(){
	ans=0;
	for(int i=1;i<=n;i++){
		maxx[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);


	c=read();
	t=read();
	while(t--){
		input();
		init();
		build(1,1,n);
		for(int i=n;i>0;i--){
			solve(i);
		}
		cout<<ans<<'\n';
		clear();
	}
//	n=3;
//	build(1,1,n);
//	add(1,1,n,1,n,1);
//	cout<<"dhw";
//	add(1,1,n,2,2,1);
//	cout<<query(1,1,n,2);
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
