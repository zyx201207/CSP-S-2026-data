#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
char In[1<<15],*uu=In,*vv=In;
template<class T>
void R(T &x){
	char c=getc();bool f=0;x=0;
	for(;!isdigit(c);f|=(c=='-'),c=getc());	
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getc());	
	f&&(x=-x);
}
using ll = long long;
const int N=5e5+5;
ll n,m,pr[N],a[N];
void solve(){
	R(n),R(m);int ans=0;
	rep(i,1,n)R(a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n)pr[i]=pr[i-1]+a[i];
	rep(i,1,n){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(pr[i]-pr[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}++r,ans=max(ans,i-r+1); 
	}cout<<ans<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
