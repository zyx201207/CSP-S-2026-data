#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
const int N=2e6+5;
int cid,T,n,L[N],R[N];ll d,a[N],f[N],g[N],cl[N],cr[N];
inline void work() {
  scanf("%d%lld",&n,&d);L[n+1]=R[n+1]=0;
  fr(i,1,n) scanf("%lld",a+i);
  L[1]=1;
  fr(i,2,n) {
    L[i]=L[i-1];
    while(a[i]-a[L[i]]>d) ++L[i];
  }
  R[n]=n;
  rp(i,n-1,1) {
    R[i]=R[i+1];
    while(a[R[i]]-a[i]>d) --R[i];
  }
  fr(i,1,n) cl[i]=cr[i]=1,f[i]=g[i]=0;
  fr(i,1,n) if(R[i]!=i) {
    if(L[R[i]]==i) cl[R[i]]+=cl[i];
    else ++cl[R[i]];
  }
  rp(i,n,1) if(L[i]!=i) {
    if(R[L[i]]==i) cr[L[i]]+=cr[i];
    else ++cr[L[i]];
  }
  fr(i,1,n) if(R[i]-i>1) {
    if(R[i-1]>=R[i]-1) ++f[R[i]-1];
    else f[R[i]-1]+=cl[i];
  }
  fr(i,1,n) if(i-L[i]>1) {
    if(L[i+1]<=L[i]+1) ++g[L[i]];
    else g[L[i]]+=cr[i];
  }
  ll ans=0;
  fr(i,1,n) ans+=f[i]*1ll*g[i];
  printf("%lld\n",ans);
  return ;
}
int main() {
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  scanf("%d%d",&cid,&T);
  while(T--) work();
	return 0;
}