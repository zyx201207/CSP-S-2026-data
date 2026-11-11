#include<bits/stdc++.h>
using namespace std;
int a[200005];
int find_1(int x){
	int cnt=0;
	while(x>0){
		if(x%2==1){
			cnt++;
		}
		x/=2;
	}
	return cnt;
}
int vis[200005];
int dp[200005];
int n,m;
void dfs(int cnt,int sum){
	if(cnt==m+1)return;
	for(int i=1;i<=n;i++){
		if(sum==-1){
			vis[i]=1;
			dp[cnt]=max(dp[cnt],a[i]);
			dfs(cnt+1,a[i]);
			vis[i]=0;
		}
		
		if(dp[cnt]>a[i]&sum)continue;
		if(vis[i])continue;
		vis[i]=1;
		dp[cnt]=a[i]&sum;
		//cout <<"OK"<<cnt<<'\n';
		dfs(cnt+1,dp[cnt]);
		
		vis[i]=0;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	//set_1();
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout << maxx;
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout << maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==n-1){
		int mini=1;
		for(int i=1;i<=n;i++){
			if(find_1(a[i])>=mini){
				mini=i;
			}
		}
		int ans=a[1];
		for(int i=2;i<=n;i++){
			if(i==mini)continue;
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(1,-1);
	cout << dp[m];
	return 0;
}

