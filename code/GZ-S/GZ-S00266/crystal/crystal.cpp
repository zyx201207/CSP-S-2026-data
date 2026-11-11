//GZ-S00266 贵阳市南明区华麟 杨博麟
#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define mid ((l+r)>>1)
#define LL long long
using namespace std;
const int N=5e5+5;
LL n,m,d[N],b[N],ans;
bool f;
struct node{
	int end;
	LL len,res,mx;
};
node t[N];
node merge(node a,node b){
	node c;
	c.end=b.end;
	c.len=a.len+b.len;
	c.res=a.len*(d[b.end]-d[a.end])+a.res+b.res;
	return c;
}
void build(int p,int l,int r){
	if(l==r){
		t[p]={l,1,0,1};
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[p]=merge(t[ls],t[rs]);
}
node ask(int p,int l,int r,int ql,int qr){
	node re={0,0,0,0};
	if(ql<=l && r<=qr) return t[p];
	if(ql<=mid) re=ask(ls,l,mid,ql,qr);
	if(mid<qr) re=merge(re,ask(rs,mid+1,r,ql,qr));
	return re;
} 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>d[1]>>d[2];
	LL x=d[1];LL y=d[2]-d[1];	
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]-d[i-1]!=y) f=1;
	}
	sort(d+1,d+1+n);
	if(!f){
		for(int i=1;i<n;i++){
			if((x+x+y*(i-1))/2*i<=m) ans=i;
			else break;
		}
		cout<<ans+1;
		return 0;
	}	
	build(1,1,n);
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			LL as=ask(1,1,n,i,j).res,mx=ask(1,1,n,i,j).len;
			if(as<=m) ans=max(ans,mx);
			else break;
		}
	}
	//cout<<ask(1,1,n-1,1,3).len+1;
	cout<<ans;
	return 0;
} 
