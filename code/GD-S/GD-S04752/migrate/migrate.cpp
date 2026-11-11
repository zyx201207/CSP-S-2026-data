//migrate
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500];
ll f[500];
ll sm[500][500];
ll dp[500][500];
ll g[500][500];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cerr<<sizeof(sm)*2/1e6;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}

		int jj=1;
		memset(f,0,sizeof(f));
		for(int i=2;i<=n;i++){
			while(jj<i&&a[i]-a[jj]>d)++jj;
			f[i]=jj;
		}
		
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			memset(sm,0,sizeof(sm));
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				dp[j][0]=1;
				if(j)
					sm[j][0]=sm[j-1][0]+1;
				else sm[j][0]=1;
			}
			for(int j=i+1;j<=n;j++){
				bool fl=(dp[j][0]==0);
				for(int k=1;k<=j-i;k++){
					if(f[j]==j)break;
					dp[j][k]=sm[j-1][k-1]-sm[f[i]][k-1];
					sm[j][k]=sm[j-1][k]+dp[j][k];
//					if(sm[i][j]<0)cerr<<'*';
//					cerr<<i<<" "<<j<<" "<<fl<<" "<<k<<" "<<sm[j-1][k-1]<<" "<<sm[f[i]][k-1]<<" "<<ans<<endl;
//					cerr<<j<<endl;
					if(fl&&dp[j][k]==2){
						++ans;fl=0;
					}
					if(dp[j][k]>0)break;
//					if(dp[i][k]>) 
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				for(int k=0;k<j-i;k++){
//					if(dp[j][k]==2)++ans;
//					if(dp[j][k])break;
//				}
//			}
//		}
//		cerr<<ans<<endl;
		cout<<ans<<'\n';
	}
	
	return 0;
}
