#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
//#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
//template<class T>
//void R(T &x){
//	char c=getc();x=0;bool f=0;
//	for(;!isdigit(c);f|=(c=='-'),c=getc());
//	for(;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getc());
//	f&&(x=-x);
//}
using ll = long long;
const int N=2e5+5;
int n,m,a[N],b[N];
void solve(){
	cin>>n>>m;ll ans=0;
	rep(i,1,n)cin>>a[i];
	per(j,30,0){
		int x=0;
		rep(i,1,n)if(a[i]>>j&1)b[++x]=a[i];
		if(x>=m){
			ans+=(1<<j),n=x;
			rep(i,1,x)a[i]=b[i];
		}
	}cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
} 
