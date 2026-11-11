#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
using namespace std;
const int maxn=1e6+10,maxm=1e6+10,mod=998244353;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int testid,T;
int n,k,ans,a[maxn],pr[maxn],fl[maxn],fr[maxn];

signed submain(){
	cin>>n>>k,ans=0;
	rep(i,1,n) cin>>a[i],fl[i]=1,fr[i]=1;
	rep(i,1,n) for(pr[i]=pr[i-1];pr[i]<n&&a[pr[i]+1]-a[i]<=k;++pr[i]);
	rep(i,1,n) if(pr[i]!=i&&pr[pr[i]-1]!=pr[pr[i]]) fl[pr[i]]+=fl[i];
	per(i,n,1) if(pr[i]!=i&&pr[i-1]!=pr[i]) fr[i]+=fr[pr[i]]-1+pr[i]-max(i,pr[i-1]);
	rep(i,1,n) if(pr[i]>i+1&&pr[pr[i]-1]!=pr[i]&&pr[pr[i]-2]!=pr[pr[i]-1])
		ans+=(pr[i-1]>=pr[i]-1?1:fl[i])*(pr[pr[i]]==pr[pr[i]-1]?(fr[pr[i]-1]-1):pr[pr[i]-1]-pr[pr[i]-2]);
	cout<<ans<<'\n';
	return 0;
}

signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>testid>>T;
	rep(o,1,T) submain();
	return 0;
}
