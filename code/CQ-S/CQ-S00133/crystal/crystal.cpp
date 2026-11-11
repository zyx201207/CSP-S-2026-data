#include<bits/stdc++.h>
#define int __int128
#define ll long long
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
using namespace std;
const int maxn=5e5+10,maxm=1e6+10,mod=998244353;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

ll n,m,ans,a[maxn];

signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int pl=1,sum=0;
	rep(i,1,n){
		if(i!=1) sum=sum-(i-1-pl+1)*(a[i-1]-a[i]);
		for(;sum>m;sum-=a[i]-a[pl],++pl);
		ans=max(i-pl+1,(int)ans);
	}
	cout<<ans;
	return 0;
}
