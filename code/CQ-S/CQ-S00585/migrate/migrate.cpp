#include<bits/stdc++.h>
#define int long long 
#define mid ((l+r)>>1)
#define ls (k<<1)
#define rs (k<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int rd(){
	int x=0;
	int f=1;
	char c=getchar();
	if(c=='-') f=-1;
	else x=(c^48);
	while(1){
		char c=getchar();
		if(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48);
		else break;
	}
	return x*f;
}
int c,t;
int n,d;
const int N=310;
int a[N],pre[N];
int sum[N<<2],minn[N<<2];
pii ask(int k,int l,int r,int x,int y){
	if(x>r||y<l) return {4e18,0};
	else if(x<=l&&y>=r) return {minn[k],sum[k]};
	else{
		pii p1=ask(ls,l,mid,x,y),p2=ask(rs,mid+1,r,x,y);
		if(p1.fi<p2.fi) return p1;
		else if(p2.fi<p1.fi) return p2;
		else return {p1.fi,p1.se+p2.se};
	} 
}
void upd(int k,int l,int r,int x,pii dx){
	if(l==r){
		sum[k]=dx.se;
		minn[k]=dx.fi;
		return;
	}
	if(x<=mid) upd(ls,l,mid,x,dx);
	else upd(rs,mid+1,r,x,dx);
	if(minn[ls]<minn[rs]){
		minn[k]=minn[ls];
		sum[k]=sum[ls];
	}
	else if(minn[rs]<minn[ls]){
		minn[k]=minn[rs];
		sum[k]=sum[rs];
	}
	else{
		minn[k]=minn[ls];
		sum[k]=sum[ls]+sum[rs];
	}
}
void solve(){
	n=rd(),d=rd();
	a[0]=-4e18;
	for(int i=1;i<=n;i++) a[i]=rd();
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		while(a[i]-a[pre[i]]>d) pre[i]++;
	}
//	for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
//	cout<<"\n";
	int ans=0;
	for(int l=1;l<=n;l++){
		memset(minn,0,sizeof minn);
		memset(sum,0,sizeof sum);
		upd(1,1,n,l,{0,1});
		for(int r=l+1;r<=n;r++){
//			if(pre[r]>=l){
				pii p=ask(1,1,n,max(pre[r],l),r-1);
				upd(1,1,n,r,{p.fi+1,p.se});
//			}
		}
		for(int r=l;r<=n;r++){
			pii p=ask(1,1,n,r,r);
//			cout<<l<<" "<<r<<" ans="<<p.fi<<" "<<p.se<<"\n";
			if(p.se==2) ans++;
		}
	}
	cout<<ans<<"\n"; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--) solve();
	return 0;
}
/*
性质1:
两条路径至多只有一个点不一样，否则一定可以搞出除此之外的三或更多路径
性质2：
不同的两个点一定是相邻的
假设a->b->c
	a->d->c
而p为b,d之间的一个点
则a->p->d也是可以的，于是就有两条以上路径了

考虑去枚举这两个相邻的点，设为t,t+1 

假设对于区间[l,r]，其直接贪心得到的为
l h1 h2 h3 ... hm r

考虑什么时候h1,h2,...hm可以改变
首先h1,h2,...hm只能往前

0 1
5 3
-3 0 2 3 4

-1 1 2 2 3
2  4 5 5 -1

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

5 3
4 6 7 8 10
*/
