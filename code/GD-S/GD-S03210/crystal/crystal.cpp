#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
#define gc getchar
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
inline int rd(){
	rint res=0,p=1;
	register char ch=gc();
	
	for(;ch<'0'||ch>'9';ch=gc()) if(ch=='-') p=-p;
	for(;ch>='0'&&ch<='9';ch=gc()) res=(res<<3)+(res<<1)+(ch^48);
	return res*p; 
}
inline bool check(const rint& l,const rint& r,const rint& ai){
	if(b[r]-b[l-1]>=ai*(r-l+1)-m) return 1;
	return 0;
}
inline int bfind(rint lim,const rint& ai){
	rint l=1,r=lim,res=lim;
	
	while(l<=r){
		rint mid=(l+r)>>1;
		
		if(check(mid,lim,ai)){
			r=mid-1;
			res=mid;
		}else l=mid+1;
	}
	return res;
}
signed main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=rd();
	m=rd();
	
	for(rint i=1;i<=n;++i)
		a[i]=rd();
	
	stable_sort(a+1,a+1+n);
	
	for(rint i=1;i<=n;++i)
		b[i]=a[i]+b[i-1];
	
	rint ans=-1;
	for(rint i=1;i<=n;++i){
		rint pos=bfind(i-1,a[i]);
		
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}

