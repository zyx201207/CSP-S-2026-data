#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N],n,m;
int tree[4*N];
void pushup(int rt){
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		tree[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	if(l<=mid)build(l,mid,rt<<1);
	if(r>mid)build(mid+1,r,rt<<1|1);
	pushup(rt);
}
int query(int l,int r,int x,int y,int rt){
	if(r<x||l>y)return 0;
	if(x<=l&&r<=y)return tree[rt];
	if(l==r)return tree[rt];
	
	int mid=(l+r)>>1;
	int rans=0;
	if(x<=mid)rans=query(l,mid,x,y,rt<<1);
	if(mid<y)rans=max(rans,query(mid+1,r,x,y,rt<<1|1));
	//printf("%d %d %d %d %d %d\n",l,r,x,y,rt,rans);
	return rans;
}
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int j=i+x-1;
		int need=(x*(query(1,n,i,j,1))-(sum[j]-sum[i-1]));
		if(m>=need){
			//printf("%d %d %d %d\n",i,j,x,need);
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//sum[i]=sum[i-1]+a[i];
		//a[i]+=inf;
		//cout<<sum[i]<<' ';
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	build(1,n,1);
	//for(int i=1;i<=4*n;i++)cout<<tree[i]<<' ';
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}
		else r=mid-1;
	}
	cout<<ans;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
