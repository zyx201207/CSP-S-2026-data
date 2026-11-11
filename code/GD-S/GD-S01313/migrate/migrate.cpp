#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+5;
int c;
ll n,d;
ll a[maxn];
int dp[maxn],cnt[maxn];
int s[maxn];
int sc[maxn];
int r;
//void dfs(int x,int cnt){
//	if(x>=r){
//		if(x==r&&cnt==dp[r])return 1;
//		return 0;
//	}
//}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1];
		if(i>1&&a[i]-a[i-1]>d)s[i]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[j]=0;
			cnt[j]=0;
			sc[j]=0;
		}
		cnt[i]=1;
		sc[i]=1;
		int lst=-1;
		int rr=0;
		for(int j=i+1;j<=n;j++){
			if(s[j]-s[i])break;
			r=j;
			int l=lower_bound(a+1,a+1+n,a[j]-d)-a;
			l=max(l,i);
			dp[j]=dp[l]+1;
			if(lst!=l){
				lst=l;
				rr=upper_bound(dp+1,dp+j,dp[l])-dp-1;
			}
			
			cnt[j]=sc[rr]-sc[l-1]; 
//			for(int k=l+1;dp[k]==dp[l];k++){
//				
//			}
//			int tmp=i;
//			int cnt=0;
//			int lst=i;
//			for(int k=i;k<=j;k++)dp[k]=0;
//			while(tmp<r){
//				while(a[tmp+1]-a[lst]<=d)tmp++;
//				
//			}	
//			cout<<i<<' '<<j<<' '<<dp[j]<<' '<<cnt[j]<<'\n'; 
			sc[j]=sc[j-1]+cnt[j];
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}


	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
