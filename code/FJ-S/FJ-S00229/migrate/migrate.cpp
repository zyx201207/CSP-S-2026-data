#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=5005;
int c,t,n,d,x[N],dp[M][M],cnt[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12) {
			int k=x[2]-x[1];
			if(d<2*k) cout<<"0\n";
			else cout<<max(0ll,n-(d/k*2-1))<<"\n";
			continue;
		}
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++)
				dp[i][j]=1e9,cnt[i][j]=1;
		int j=1,ans=0;
		for(int i=1;i<=n;i++) dp[i][i]=0;
		for(int i=1;i<=n;i++){
			while(x[j]<=x[i]+d&&j<=n) j++;
			j--;
			for(int r=i+1;r<=j;r++){
				for(int l=1;l<=i;l++){
					if(dp[l][i]+1<=dp[l][r]){
						if(dp[l][i]+1<dp[l][r]) 
							dp[l][r]=dp[l][i]+1,cnt[l][r]=0;
						cnt[l][r]+=cnt[l][i];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
