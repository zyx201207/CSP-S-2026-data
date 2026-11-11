#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
struct node{int mn,sum;}tr[N<<2];
inline node merge(node x,node y){
	if(x.mn==y.mn) return {x.mn,min(3,x.sum+y.sum)};
	if(x.mn>y.mn) swap(x,y);
	return x;
}
struct Tree{
	inline void upd(int pos,int d,int di,int p=1,int pl=1,int pr=N){
		if(pl==pr){tr[p]={di,d};return;}int mid=pl+pr>>1;
		pos<=mid?upd(pos,d,di,p<<1,pl,mid):upd(pos,d,di,p<<1|1,mid+1,pr);
		tr[p]=merge(tr[p<<1],tr[p<<1|1]);
	}
	inline node ask(int l,int r,int p=1,int pl=1,int pr=N){
		if(l<=pl&&pr<=r) return tr[p];int mid=pl+pr>>1;
		if(r<=mid) return ask(l,r,p<<1,pl,mid);
		if(l>mid) return ask(l,r,p<<1|1,mid+1,pr);
		return merge(ask(l,r,p<<1,pl,mid),ask(l,r,p<<1|1,mid+1,pr));
	}
}ds;
int c,T,n;ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		ll ans=0;
		for(int a=1;a<=n;a++){
			ds.upd(a,1,0);
			for(int i=a+1,k=a;i<=n;i++){
				if(x[i]-x[i-1]>d) break;
				while(x[i]-x[k]>d) k++;
				node u=ds.ask(k,i-1);
				ds.upd(i,u.sum,u.mn+1);
				ans+= u.sum==2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
