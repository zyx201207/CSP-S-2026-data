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
int n,a[N];
char c[N];
void solve(){
	cin>>n;ll ans=0;
	rep(i,1,n)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]==a[r])++l,--r;
			else if(a[l]>a[r])a[l]-=a[r],--r;
			else a[r]-=a[l],++l;
		}
		else{
			if(a[l]==a[r])ans+=a[l],++l,--r;
			else if(a[l]>a[r])ans+=a[r],a[l]-=a[r],--r;
			else ans+=a[l],a[r]-=a[l],++l;
		}
	}cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
/*
2
1 a
2 b

*/ 
