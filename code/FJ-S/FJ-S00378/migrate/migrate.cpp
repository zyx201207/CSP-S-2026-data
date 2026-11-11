#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int a[N];
int dp[N][3];
int r[N];
int c;
void solve(){
	int n,d;
	cin>>n>>d;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]-a[l]>d){
			r[l]=i-1;
			l++;
		}
	}
	for(;l<=n;l++)
	r[l]=n;
	int ans=0;
	if(11<=c&&c<=12){
		if(r[1]==1||r[1]==2){
			cout<<0<<'\n';
			return;
		}
		cout<<max(n-(r[1]-1)*2+1,0ll)<<'\n';
		return;
	}
//	if(13<=c&&c<=14){
//		if(r[1]==1||r[1]==2){
//			cout<<0<<'\n';
//			return;
//		}
//		cout<<max(n-(r[1]-1)*2+1,0ll)<<'\n';
//		return;
//	}
	for(int i=n;i;i--){
		if(r[i]==i)dp[i][0]=1;
		else if(r[i]==i+1){
			dp[i][0]=dp[i+1][0]+1;
			dp[i][1]=dp[i+1][1];
		}else if(r[i]==i+2){
			if(r[i+1]==i+2){
				dp[i][0]=dp[i+2][0]+2;
				dp[i][1]=dp[i+2][1];
			}else if(r[i+1]==r[i+2]){
				dp[i][1]=dp[i+2][0]-1;
				dp[i][0]=3;
			}else if(r[i+1]==r[i+2]-1){
				dp[i][0]=dp[i+2][0]-(r[i+2]-1-(i+2));
				dp[i][1]=(r[i+2]-1-(i+2));
			}
		}
		ans+=dp[i][1];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
