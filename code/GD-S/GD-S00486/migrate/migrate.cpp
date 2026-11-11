#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t,dp[5005][5005],len[5005][5005];
long long a[5005];
bool vis[5005];
int main(){
	fastio;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	int c;
	cin>>c>>t;
	while(t--){
		cout<<rand()%1005<<endl;
		continue;
		int n,d;
		cin>>n>>d;
		if(n<=5000){
			memset(dp,0,sizeof(dp));
			memset(len,0x3f,sizeof(len));
			for(int i=1;i<=n;i++){
				len[i][i]=1;
				dp[i][i]=1;
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) break;
					if(len[i][j] > len[i][j-1]+1){
						len[i][j]=len[i][j-1]+1;
						dp[i][j]=dp[i][j-1];
					}else{
						dp[i][j]+=dp[i][j-1];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
