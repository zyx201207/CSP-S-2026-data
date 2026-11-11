#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX/2
int n,m,a[2000006],dp[5005][5005],cnt[5005][5005];
void solve(){
	memset(dp,0x3f,sizeof dp);
	memset(cnt,0,sizeof cnt);
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;a[i]-a[j]<=m&&j>=1;j--){
			dp[j][i]=1;cnt[j][i]=1;
			for(int k=1;k<j;k++){
				if(dp[k][i]==dp[k][j]+1)cnt[k][i]++;
				else if(dp[k][i]>dp[k][j]+1){
					dp[k][i]=dp[k][j]+1;
					cnt[k][i]=1;
				}
			}
		}
//		for(int i=1;i<n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(cnt[i][j]==2)ans++;
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
			//cout<<cnt[i][j]<<" ";
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
}
void solve1(){
	int k=a[2]-a[1];
	if(k>m||m/k==1){
		cout<<0;
		return ;
	}
	k=m/k;
	int sum=n*(n-1)/2,num=0;
	for(int i=k;i<=n;i+=k)num+=n-i;
	cout<<sum-num;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		if(c==11||c==12)solve1();
		else if(c<=6)solve();
	}
	return 0;
}
