#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef pair<int,int> PII;
const int N=5e5+114;
int a[N];
int dp[N];//dp【i】必选i，选i个以前的最多能多少，包括自己，dp[i]>=1 
int dpc[N];//当前dp的代价 
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+1;
		dpc[i]=dpc[i-1]+dp[i-1]*(a[i]-a[i-1]);
		while(dpc[i]>m){
			dpc[i]-=a[i]-a[i-dp[i]+1];
			dp[i]--;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}
signed main(){
	IOS
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}

/*

dp【i】必选i，选i个以前的最多能多少
 









反悔贪心
一个一个来，
从小到大排序
一个一个加
加更大的代价后小于m就加
如果大于m加更大的代 


*/
