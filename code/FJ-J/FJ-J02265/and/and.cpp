#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct Node{
	int cnt,num;
};
int n,m;
int a[N];
Node dp[N][2];
//void solve(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		dp[i][1].num=a[i];
//		dp[i][1].cnt=1;
//		dp[i][0].num=0;
//	}
//	for(int i=2;i<=n;i++){
//		//不选第i个
//		dp[i][0].num=max(dp[i-1][0].num,dp[i-1][1].num);
//		if(dp[i-1][0].num<dp[i-1][1].num){
//			dp[i][0].cnt=dp[i-1][1].cnt;
//		}else{
//			dp[i][0].cnt=dp[i-1][0].cnt;
//		}
//		//选第i个  
//		int l=0,_l=0;
//		if(dp[i-1][0].cnt<m){
//			l=(dp[i-1][0].num&a[i]);
//			dp[i][1].cnt=dp[i-1][0].cnt+1;
//		}
//		if(dp[i-1][1].cnt<m){
//			_l=(dp[i-1][1].num&a[i]);
//			if(dp[i-1][0].cnt<m){
//				if(l<=_l){
//					dp[i][1].cnt=dp[i-1][1].cnt+1;
//				}else{
//					dp[i][1].cnt=dp[i-1][0].cnt+1;
//				}
//			}else{
//				dp[i][1].cnt=dp[i-1][1].cnt+1;
//			}
//		}
//		if(dp[i][1].num>max(_l,l)){
//			dp[i][1].num=a[i];
//			dp[i][1].cnt=1;
//		}else{
//			dp[i][1].num=max(_l,l);
//		}
//		cout<<dp[i][0].num<<" "<<dp[i][1].num<<endl;
//	}
//	int ans=0;
//	for(int i=2;i<=n;i++){
//		if(dp[i][0].cnt==m){
//			ans=max(dp[i][0].num,ans);
//		}
//		if(dp[i][1].cnt==m){
//			ans=max(dp[i][1].num,ans);
//		}
//	}
//	cout<<ans;
//	return;
//}
int an;
bool st[N];
void dfs(int u,int cnt,int ans){
	if(cnt==m){
		an=max(ans,an);
		return;
	}
	//不选 
	dfs(u+1,cnt,ans);
	//选 
	dfs(u+1,cnt+1,(ans&a[u]));
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return;
	}
	dfs(0,0,2147483647);
	cout<<an;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--)solve();
	return 0;
}
