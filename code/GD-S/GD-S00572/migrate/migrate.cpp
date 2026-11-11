#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int c,n,d,a[N],ans;
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c>6){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]-a[1]<=d)cnt=i-1;
		cout<<n-(cnt+cnt-1)<<'\n';
		return;
	}
	vector<vector<int>>dis(n+1,vector<int>(n+1,2e18+5)),cnt(n+1,vector<int>(n+1,0));
	
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)if(a[j]-a[i]<=d)dis[i][j]=cnt[i][j]=1;
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(dis[i][k]+dis[k][j]<dis[i][j]){
			dis[i][j]=dis[i][k]+dis[k][j];
			cnt[i][j]=cnt[i][k]*cnt[k][j];
		}
		else if(dis[i][k]+dis[k][j]==dis[i][j]){
			cnt[i][j]+=cnt[i][k]*cnt[k][j];
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)if(cnt[i][j]==2)ans++;
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>c>>t;
	while(t--)solve();
}
