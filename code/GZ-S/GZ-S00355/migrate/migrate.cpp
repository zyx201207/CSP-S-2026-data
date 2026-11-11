//观山湖中学 梁洪锐 GZ-S00355 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f,mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
void solve(){
	int n,d;
	cin>>n>>d;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector< vector<int> >dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=1,c;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
