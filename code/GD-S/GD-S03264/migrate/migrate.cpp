#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,t,n,d,ar[N],dp[2000][2000],ans,cnt[2000][2000];
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	memset(dp,0x3f,sizeof dp);
	memset(cnt,0,sizeof cnt);
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if(ar[j]-ar[i]<=d) {
				dp[i][j]=1;
				cnt[i][j]=1;
			}
			else{
				for(int k=i+1;k<j;k++){
					if(ar[j]-ar[k]<=d&&dp[i][j]>dp[i][k]+1){
						dp[i][j]=dp[i][k]+1;
						cnt[i][j]=cnt[i][k];
					}
					else if(dp[i][j]==dp[i][k]+1){
						cnt[i][j]+=cnt[i][k];
					}
				}
				
				if(cnt[i][j]==2) ans++;
			}
		//	cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}


	return 0;
}

