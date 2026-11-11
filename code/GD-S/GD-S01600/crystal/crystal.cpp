#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define int long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
const int mod=1;
template<typename T>inline void cmin(T&x,T y){x=(x<y?x:y);}
template<typename T>inline void cmax(T&x,T y){x=(x>y?x:y);}
template<typename T>inline int fplus(T x,T y){return x+y-(x+y>=mod?mod:0);}
template<typename T>inline void cplus(T&x,T y){x=fplus(x,y);}
template<typename T>inline int fminus(T x,T y){return x-y+(x-y<=0?mod:0);}
template<typename T>inline void cminus(T&x,T y){x=fminus(x,y);}
template<typename T>inline int qp(T x,T y){
	T ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ans;
}
bool be;
int n,m,a[500005],sum[500005],ans;
void solve(){
	cin>>n>>m;
	fo(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	fo(i,1,n){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1,mid,tmp=i;
		while(l<=r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)tmp=mid,r=mid-1;
			else l=mid+1;
		}
		cmax(ans,i-tmp+1); 
	}
	cout<<ans;
}
bool bg;
signed main(){
//	#ifndef QWERTIM
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
//	#endif
//	freopen("crystal4.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
//	cerr<<'\n'<<abs((&be)-(&bg))/1048576.;
	return 0;
}
