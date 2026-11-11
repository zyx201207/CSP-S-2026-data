#include <bits/stdc++.h>
#define LL long long
#define sc(a) cout<<(a)<<"\n"
#define sx(a,b) cout<<(a)<<" "<<(b)<<"\n"
using namespace std ;
const int N=3005+10 ;
LL n,d,a[2000004] ;
LL f[N][N],g[N][N] ;
LL q[2000004],h,t,ans ;
void FZ () {
	cin>>n>>d ;
	for (int i=1;i<=n;i++) {
		cin>>a[i] ;
	}
	LL ans=0 ;
	for (int s=1;s<=n;s++) {
		g[s][s]=1 ;
		f[s][s]=0 ;
		h=1 ; t=0 ; q[++t]=s ;
		for (int i=s+1;i<=n;i++) {
			while (h<=t && a[i]-a[q[h]]>d) h++ ;
			if (h<=t) f[s][i]=f[s][q[h]]+1,g[s][i]=g[s][q[h]] ;
			else f[s][i]=1e18,g[s][i]=-1e18 ;
			if (t-h+1==1) {
				if (g[s][q[h]]==2) ans++,g[s][i]=g[s][q[h]] ;
//				else g[s][i]=-1e18 ;
			}
			else if (t-h+1>=2 && f[s][q[h]]==f[s][q[h+1]]) {
				if (t-h+1>=3 && f[s][q[h+2]]==f[s][q[h+1]]) g[s][i]=1e18 ;
				else if (g[s][q[h]]+g[s][q[h+1]]==2) ans++,g[s][i]=2 ;
				else g[s][i]=1e18 ;
			}
			else if (g[s][q[h]]==2 && f[s][q[h]]!=f[s][q[h+1]]) {
				ans++ ; g[s][i]=2 ;
			}
			if (f[s][i]==1e18) continue ;
			while (h<=t && f[s][i]<f[s][q[t]]) t-- ;
			q[++t]=i ;
		}
	}
	cout<<ans<<'\n' ;
}
LL F[2000004],G[2000004] ;
void FZ1 () {
	cin>>n>>d ;
	for (int i=1;i<=n;i++) {
		cin>>a[i] ;
	}
	LL ans=0 ;
	for (int s=1;s<=1;s++) {
		G[s]=1 ;
		F[s]=0 ;
		h=1 ; t=0 ; q[++t]=s ;
		for (int i=s+1;i<=n;i++) {
			while (h<=t && a[i]-a[q[h]]>d) h++ ;
			if (h<=t) F[i]=F[q[h]]+1,G[i]=G[q[h]] ;
			else F[i]=1e18,G[i]=-1e18 ;
			if (t-h+1==1) {
				if (G[q[h]]==2) ans+=n-i+1,G[i]=G[q[h]] ;
			}
			else if (t-h+1>=2 && F[q[h]]==F[q[h+1]]) {
				if (t-h+1>=3 && F[q[h+2]]==F[q[h+1]]) G[i]=1e18 ;
				else if (G[q[h]]+G[q[h+1]]==2) ans+=n-i+1,G[i]=2 ;
				else G[i]=1e18 ;
			}
			else if (G[q[h]]==2 && F[q[h]]!=F[q[h+1]]) {
				ans+=n-i+1 ; G[i]=2 ;
			}
			if (F[i]==1e18) continue ;
			while (h<=t && F[i]<F[q[t]]) t-- ;
			q[++t]=i ;
		}
	}
	cout<<ans<<'\n' ;
}
int main () { 
//	system ("fc hh migrate3.ans") ;
	freopen ("migrate.in","r",stdin) ;
	freopen ("migrate.out","w",stdout) ;
//	freopen ("migrate3.in","r",stdin) ;
//	freopen ("hh","w",stdout) ;
	int c,T ; cin>>c>>T ; 
	if (c!=11 && c!=12) while (T--) FZ() ;
	else while (T--) FZ1 () ; 
	return 0 ;
} 
