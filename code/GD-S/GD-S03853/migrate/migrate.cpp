//migrate GYSQ 
#include<bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int V,T;
inline void read(int &x){
	char c;int f=1;
	while(!isdigit(c=getchar())) f=c=='-'?-1:1;
	x=c-'0';
	while(isdigit(c=getchar())) x=x*10+c-'0';
	x*=f;
}
inline void write(int x,bool f=1){if(x||f) write(x/10,0),putchar(x%10+'0');}
namespace F{
	int n,d,a[5010];
	pii t[5010];
	int cnt[5010];
	int ans;
	inline pii merge(pii a,pii b){return a.f!=b.f?min(a,b):pii({a.f,a.s+b.s});}
	namespace SGT{
		#define li (k<<1)
		#define ri (k<<1|1)
		#define mi (l+r>>1)
		pii val[20010];
		void init(int k,int l,int r){
			val[k]={n+1,0};
			if(l!=r) init(li,l,mi),init(ri,mi+1,r);
		}
		void modi(int k,int l,int r,int v,pii x){
			val[k]=merge(val[k],x);
			if(l!=r&&v<=mi) modi(li,l,mi,v,x);
			if(l!=r&&v>mi) modi(ri,mi+1,r,v,x); 
		}
		pii query(int k,int l,int r,int L,int R){
			if(L<=l&&R>=r) return val[k];
			pii res={n+1,0};
			if(L<=mi) res=merge(res,query(li,l,mi,L,R));
			if(R>mi) res=merge(res,query(ri,mi+1,r,L,R));
			return res;
		}
	}
	inline void slv(){
		read(n),read(d);
		ans=0;
		for(int i=1;i<=n;i++){
			read(a[i]);
			SGT::init(1,1,n);
			SGT::modi(1,1,n,i,{0,1});
			for(int j=i-1,k=i;j>=1;j--){
				while(a[k]-a[j]>d) k--;
				t[j]=SGT::query(1,1,n,j+1,k);
				t[j].f++;
				SGT::modi(1,1,n,j,t[j]);
				if(t[j].s==2) ans++;
			}
		}
		write(ans),putchar(' ');
	}
}
namespace A{
	int n,d,t,a[2000010];
	void slv(){
		read(n),read(d);
		for(int i=1;i<=n;i++) read(a[i]);
		if(n==1||d<=abs(a[2]-a[1])){puts("0");return;}
		printf("%lld\n",max(n-d/abs(a[2]-a[1])*2+1,0ll));
	}
}
namespace B{
	void slv(){
		
	}
}
inline void slv(){
	if(V<=10) F::slv();
	else if(V<=12) A::slv();
	else B::slv();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&V,&T);
	while(T--) slv();
	return 0;
}
