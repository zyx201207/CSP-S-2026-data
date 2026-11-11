#include<bits/stdc++.h>
#define int long long
#define INF 2e18
using namespace std;
const int N=5e3+10;
int x[N],R[N],L[N];
int g[N][N],f[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			R[i]=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[mid]-x[i]<=d){
					l=mid+1;
					R[i]=mid;
				}
				else{
					r=mid-1;
				}
			}
			l=1,r=i,L[i]=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[i]-x[mid]<=d){
					r=mid-1;
					L[i]=mid;
				}
				else{
					l=mid+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=INF;
			}
		}
		for(int i=1;i<=n;i++){
			g[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			int x=i;
			while(R[x]!=x){
				for(int j=x+1;j<=R[x];j++){
					g[i][j]=g[i][x]+1;
				}
				x=R[x];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				f[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			f[i][i]=1;
		}
		int ans=0;
		for(int j=n;j>=1;j--){
			int l=j,r=j,sum=0;
			for(int i=j-1;i>=1;i--){
				while(l>=i&&g[l][j]==g[i][j]-1){
					sum+=f[l][j];
					l--;
				}
				while(r>=l&&x[r]-x[i]>d){
					sum-=f[r][j];
					r--;
				}
				f[i][j]=sum;
				if(f[i][j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
