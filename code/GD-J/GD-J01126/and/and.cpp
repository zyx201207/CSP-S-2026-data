#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e5+5;
int n,m;
int a[maxn];
int dp[maxn];
bool vis[maxn];
int ans = -1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		memset(dp,-1,sizeof dp);
		memset(vis,false,sizeof vis);
		int first = a[i];
		vis[i] = true;
		dp[1] = first;
		int pos;
		for(int po=1;po<=n;po++){
			if(vis[po]) continue;
			if((first&a[po]) > dp[2]){
				dp[2] = (first&a[po]);
				pos = po;
			}
		}
		vis[pos] = true;
		for(int j=3;j<=m;j++){
			for(int po=1;po<=n;po++){
				if(vis[po]) continue;
				if(dp[j-1]&a[po] > dp[j]){
					dp[j] = (dp[j-1]&a[po]);
					pos = po;
				}
			}
			vis[pos] = true;
		}
		ans = max(ans,dp[m]);
	}
	cout << ans;
	return 0;
}

//#include<bits/stdc++.h>
//#define int long long
//#define endl '\n'
//using namespace std;
//const int maxn = 2e5+5;
//int n,m;
//int a[maxn];
//int dp[maxn];
//bool vis[maxn];
//int ans = -1;
//signed main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	freopen("and3.in","r",stdin);
//	freopen("and3.out","w",stdout);
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)cin >> a[i];
//	dp[0] = (1 << 32)-1;
//	for(int j=1;j<=m;j++){
//		int pos = -1;
//		for(int po=1;po<=n;po++){
//			if(vis[po]) continue;
//			if(dp[j-1]&a[po] > dp[j]) {
//				dp[j] = (dp[j-1]&a[po]);
//				pos = po;
//			}
//		}
//		if(pos != -1)vis[pos] = true;
//		else cout <<"!!!!!!!";
//	}
//	//for(int i=1;i<=n;i++) cout<< vis[i] << " ";
//	ans = max(ans,dp[m]);
//	cout << ans;
//	return 0;
//}
