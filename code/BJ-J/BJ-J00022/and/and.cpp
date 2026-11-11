#include <bits/stdc++.h>
using namespace std;
int dp[1145][2];
int a[114514];
int n,m,ans;
void dfs(int sum,int k,int xb){
	if (sum==m){
		ans=max(ans,k);
		return;
	}for (int i=xb+1;i<=n;i++){
		if (k==0)k=a[i];
		dfs(sum+1,int(k&a[i]),i);
		
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}if (m==n){
		int t=0;
		for (int i=1;i<=n;i++){
			t=int(t&a[i]);
		}cout<<t;
		return 0;
	}else if (m==1){
		int t=0;
		for (int i=1;i<=n;i++){
			t=max(a[i],t);
		}cout<<t;
		return 0;
	}else if (m==2){
		int t=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (i!=j)t=max(t,a[i]&a[j]);
				cout<<i<<" "<<j<<" "<<int(a[i]&a[j])<<"\n";
			}
		}cout<<t;
		return 0;
	}else if (n<=20){
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}for (int i=1;i<=n;i++){
		dp[n][0]=0;
	}//cout<<int(0|3);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (dp[i][j]!=0)dp[i][j]=max(dp[i][j],int(dp[i-1][j-1]&a[i]));
			else dp[i][j]=a[i];
		}
	}/*for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<"\n";
	}*/
	cout<<dp[n][m];
	
	return 0;
}