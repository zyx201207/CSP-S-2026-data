#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define ll long long
#define ull unsigned long long
int c,t;
ll n,d,x[N],ans,dp[N][N],cnt[N][N];
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=cnt[i][j]=0;
	for(int i=n;i>=1;i--){
		int pos=0;
		cnt[i][i]=1;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d) pos=j;
			dp[i][j]=1+dp[pos][j];
			int now=pos;
			while(now>i&&cnt[i][j]<=2&&dp[now][j]==dp[pos][j]) cnt[i][j]+=cnt[now][j],--now;
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
