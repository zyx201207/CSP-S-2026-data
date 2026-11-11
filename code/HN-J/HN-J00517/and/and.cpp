#include<bits/stdc++.h>
using namespace std;
long long dp[200005],a[200005],max1=0;
int n,m,f;
int vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1]=max(dp[1],a[i]);
		if(dp[1]==a[i])f=i;
	}
	vis[f]=1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				max1=max(max1,(a[i]&a[j]));
			}
		}
		cout<<max1;
		return 0;
	}
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			dp[j]=max(max(dp[j],(dp[j-1]&a[i])),(a[i]&a[i-1]));
			if(dp[j]==(dp[j-1]&a[i]))f=i;
			if(dp[j]==dp[j-1])break;
		}
		vis[f]=1;
	}
	cout<<dp[m];
	return 0;
}
