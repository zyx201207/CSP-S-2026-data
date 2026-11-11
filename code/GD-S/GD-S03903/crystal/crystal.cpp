#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int n,m,arr[N],dp[5005][5005],ans,ans1,s[N],k,sum2;
void dfs(int k,int idx,int sum,int cnt){
	if(sum<=m){
		if(idx==k+1) {
			ans=max(cnt,ans);
			return;
		}
		if(sum==m) return;
	}
	if(idx==k+1) return;
	dfs(k,idx+1,sum+dp[idx][k],cnt+1);
	dfs(k,idx+1,sum,cnt);
}
bool f1=1,f2=1;
signed main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		s[i]=s[i-1]+arr[i];
		if(arr[i]!=i) f1=0;
		if(i>1&&i<n&&arr[i]-arr[i-1]!=arr[i+1]-arr[i]) f2=0;
	} 
	if(f1==1){
		for(int i=1;i<=n;i++){
			if(s[i]==m){
				cout<<i+1;
				return 0;
			}
			if(s[i]>m){
				cout<<i;
				return 0;
			}
		}
	}
	if(f2==1){
		int k=arr[2]-arr[1],cnt2=0;
		if(m<k){
			cout<<1;
			return 0;
		}
		for(int i=k;i<=n;i*=3){
			cnt2++;
			if(m>=i&&m<=3*i-1){
				cout<<cnt2+1;
				return 0;
			}
		}
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=arr[j]-arr[i];
			sum2+=dp[i][j];
		}
	}
	if(sum2<=m){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		dfs(i,1,0,0);
		ans1=max(ans1,ans);
	}
	if(ans1>=n) cout<<n;
	else cout<<ans1+1;
	return 0;
} 
