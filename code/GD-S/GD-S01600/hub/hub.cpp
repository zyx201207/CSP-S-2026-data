#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
const int mod=qwq;
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
void solve(){

}
bool bg;
signed main(){
	#ifndef QWERTIM
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	#endif
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	cerr<<'\n'<<abs((&be)-(&bg))/1048576.;
	return 0;
}
