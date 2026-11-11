#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int a[N];
int w[N];
int v[N];
int dp[N][N]; 
int n,m;
int ans = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		int x;
		cin>>x;
		for(int i = 2;i<=n;i++){
			int l;
			cin>>l;
			x&=l;
		}
		cout<<x<<endl;
	}
	if(m==2){
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		w[i] = 1,v[i] = x;
		dp[i-1][0] = v[i];
	}
	dp[0][1] = v[1];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			int p = dp[i][j-w[i]]&v[i];
			dp[i][j] = max(dp[i-1][j],p);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

