#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=1e6+5;
ll n,m,a[N],fa[N],si[N],la[N],ans[N],val[N];
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	For(i,1,n)a[i]=read(),fa[i]=i,si[i]=1,la[a[i]]=i;
	val[n]=a[n];
	for(ll i=1;i<n;++i){
		if(la[a[i]]!=i){
			fa[i]=la[a[i]],si[la[a[i]]]+=si[i];
			continue;
		}
		else{
			val[i]=a[i];
			fa[i]=i+1,si[i+1]+=si[i];
		}
	}
	For(i,1,n)if(val[i])ans[val[i]]+=si[i];
	For(i,1,m)printf("%lld ",ans[i]);
	return 0;
}


