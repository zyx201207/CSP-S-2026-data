#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=2e6+15,inf=5e18;
int C,T,n,d,a[N],fa[N],L[N],R[N],ans,lf[N],rf[N];
//lfx,rfx Îª Ri=xµÄ·¶Î§ 
vector<int> e[N];
int g[500005],cnt=0;
inline int chk(int l,int r,int x){
	if(!lf[x]&&!rf[x]) return 0;
	return max(0ll,min(r,rf[x])-max(l,lf[x])+1);
}
/*
0 1
5 2
-5 -4 -3 -2 -1
*/
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<=n+1;i++) lf[i]=rf[i]=L[i]=R[i]=g[i]=fa[i]=0;
		a[0]=-inf,a[n+1]=inf;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int l=0,r=i-1,mid,res=i-1;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[i]-a[mid]>d) res=mid,l=mid+1;
				else r=mid-1;
			}
			L[i]=res+1;
			fa[i]=L[i],e[L[i]].pb(i);
			l=i+1,r=n+1,res=i+1;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[mid]-a[i]>d) res=mid,r=mid-1;
				else l=mid+1;
			}
			R[i]=res-1;
		}
		for(int i=1;i<=n;i++){
			if(!lf[R[i]]) lf[R[i]]=i;
			rf[R[i]]=i;
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			int x=i;
			while(x){
				g[++cnt]=x;
				if(x==fa[x]) break;x=fa[x];
			}
			reverse(g+1,g+cnt+1);
			int op=1;
			g[0]=g[1];
			for(int j=cnt-1;j>=1;j--){
				int ls=g[j-1],md=g[j],rs=g[j+1];
				if(op==1){
					if(md+1<rs) ans+=chk(ls,md,md+1);
					if(R[ls]==md+1) op=0;
					if(R[ls]>md+1) break;
				}
				else{
					ans+=chk(ls,md,md);
					if(md+1==rs) ans+=chk(ls,md,md+1);
					if(R[ls]>md) break;
				}
				if(g[i]==g[i-1]) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
