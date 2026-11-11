#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
struct node{ll a;int s;}b[N];
int n;ll m,a[N];
int bs;int z;
#define lb(i) (i&-i)
ll tr[N];
void ad(int i,ll a){
	for(;i<=bs;i+=lb(i))tr[i]+=a;
}
ll cha(int x){
	ll s=0;
	for(;x;x-=lb(x))s+=tr[x];
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("D:/csps-new/down/crystal/crystal4.in","r",stdin);//
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=1,s=1;i<=n;i++){
		if(i<n&&a[i]==a[i+1])++s;
		else b[++bs]={a[i],s},s=1;
	}
	z=b[1].s;
	for(int i=2;i<=bs;i++){
		ad(1,b[i].a-b[i-1].a);
		ad(i,b[i-1].a-b[i].a);
		ll tm=m;int s=b[i].s;
		for(int j=i-1;j>=1;j--){
			ll t=cha(j);
			if(tm/t<b[j].s){
				s+=tm/t;
				break;
			}s+=b[j].s;
			tm-=t*b[j].s;
		}z=max(z,s);
	}
	printf("%d",z);
	return 0;
}/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
struct node{ll a;int s;}b[N];
int bs,n;ll m,a[N];
int sz[N],z;
#define lb(i) (i&-i)
struct tree{
	ll tr[N];
	tree(){memset(tr,0,sizeof(tr));}
	void ad(int i,ll a){
		for(;i<=bs;i+=lb(i))tr[i]+=a;
	}
	ll cha(int y){
		ll s=0;
		for(;y;y-=lb(y))s+=tr[y];
		return s;
	}
}c;
struct tree2{
	ll tr[N];
	tree2(){memset(tr,0,sizeof(tr));}
	void ad(int i,ll a){
		for(;i<=bs;i+=lb(i))tr[i]+=a*(sz[i]-sz[i-lb(i)]);
	}
	ll cha(int x,int y){
		ll s0=0,s1=0;
		for(--x;x;x-=lb(x))s0+=tr[x];
		for(;y;y-=lb(y))s1+=tr[y];
		return s1-s0;
	}
}s;
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=1,s=1;i<=n;i++){
		if(i<n&&a[i]==a[i+1])++s;
		else b[++bs]={a[i],s},s=1;
	}
	for(int i=1;i<=n;i++)sz[i]=sz[i-1]+b[i].s;
	z=b[1].s;
	for(int i=2;i<=bs;i++){
		c.ad(1,b[i].a-b[i-1].a);
		c.ad(i,b[i-1].a-b[i].a);
		s.ad(1,b[i].a-b[i-1].a);
		s.ad(i,b[i-1].a-b[i].a);
		
		printf("i%d: ",i);
		for(int j=1;j<i;j++)printf("(%d:%lld)",j,c.cha(j));
		puts("");
		
		int l=1,r=i-1;
		while(l<=r){
			int md=l+r>>1;
			if(s.cha(md,i-1)>m)l=md+1;
			else r=md-1;
		}++r;
		if(r==i){z=max(z,b[i].s);continue;}
		if(r==1){z=max(z,sz[i]);continue;}
//		long long t=m-s.cha(r,i-1),tt=c.cha(r-1,r-1);
		long long t=(m-s.cha(r,i-1))/(c.cha(r-1));
		z=max(z,sz[i]-sz[r-1]+int(t));
	}
	printf("%d",z);
	return 0;
}*/
