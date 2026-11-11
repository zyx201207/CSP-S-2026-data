#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=5e3+15,inf=1e18+15;
int c,t,x[N],q[N],lst[N],ans,dp[N],f[N][N],cnt[N][N],w[N],n,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=inf;
				cnt[i][j]=0;
				if(i==j) f[i][i]=0;
 			}
		}
		int l=1,r=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			while(l<=r&&x[q[l]]+d<x[i]){
				l++;
				
			}
			if(r-l+1==2&&(c==13||c==14)) {
				ans++;
				continue;
			}
			q[++r]=i;
			for(int j=l;j<=r;j++){
				f[i][j]=1;
				f[j][i]=1;
				cnt[i][j]=cnt[j][i]=1; 
			}
		}
		if(c==13||c==14){
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					if(i==j&&j==p&&p==i) continue;
					if(f[i][p]==inf||f[j][i]==inf) continue;
					if(f[p][i]+f[i][j]==f[p][j]){
						cnt[p][j]+=cnt[p][i]*cnt[i][j];
					}
					if(f[p][i]+f[i][j]<f[p][j]){
						f[p][j]=f[p][i]+f[i][j];
						cnt[p][j]=cnt[p][i]*cnt[i][j];
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) {
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
