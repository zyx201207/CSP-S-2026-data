#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300+10;
const int inf=2000000000000000010; 
const int M=2e6+10;
using PII=pair<int,int>;
int c,t,n,d,x[M],dp[N][N],cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(11<=c&&c<=12){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n==1){
				cout<<"0\n";
				continue; 
			}
			int y=x[2]-x[1];
			for(int i=1;i<=n;i++){
				int cnt=(n-i)*y;
				ans+=max(0LL,((cnt+d-1)/d)-1LL);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(13<=c&&c<=14){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n==1){
				cout<<"0\n";
				continue; 
			}
			sort(x+1,x+n+1);
			int ans=0;
			for(int i=1;i<=n;i++){
				int id1=upper_bound(x+i,x+n+1,d)-x-1;
				int id2=upper_bound(x+i,x+n+1,d*2)-x-1;
				id1=id1-i+1;
				id2=id2-i+1;
				if(id1==2){
					ans+=(id2-id1);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		else{
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				for(int j=1;j<=n;j++){
					dp[i][j]=inf;
					cnt[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						dp[i][j]=1;
						cnt[i][j]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dp[i][k]>=inf||dp[k][j]>=inf) continue;
						if(dp[i][j]>dp[i][k]+dp[k][j]){
							dp[i][j]=dp[i][k]+dp[k][j];
							cnt[i][j]=cnt[i][k]*cnt[k][j];
							continue;	
						}
						if(dp[i][j]==dp[i][k]+dp[k][j]){
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
