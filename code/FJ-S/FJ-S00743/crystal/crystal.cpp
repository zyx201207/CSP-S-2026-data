#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define N 1000005
#define HMY return
#define pb push_back()
#define pii pair<int,int>
int n,m,a[N],s[N],ans=-1e18;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	FILE("crystal")
	cin>>n>>m;
	int l=1,r=1,dp[N],w[N];//queue
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[i]=1,w[i]=0;//dp init
	int i=1;
	while(i<=n){
		if(w[i-1]+(i-1)*(a[i]-a[i-1])<=m) dp[i]=dp[i-1]+1,w[i]=w[i-1]+(i-1)*(a[i]-a[i-1]);
		else{
			//cout<<"111"<<r<<'\n';
			int q=w[i-1]+(i-1)*(a[i]-a[i-1]);
			while(q>m&&l<=r){
				l++;
				q-=(a[r]-a[l-1]);
			}
			dp[i]=r-l+1;
			w[i]=q;
		}
		//cout<<dp[i]<<'\n';
		r++,i++;
	}
	//for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	//cout<<'\n';
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	HMY 0;
}
/*
5 8
-3 -1 2 2 7
*/
