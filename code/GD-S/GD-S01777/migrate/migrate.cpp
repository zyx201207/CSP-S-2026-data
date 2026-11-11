#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[50001],dp[5001][5001];

void f(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int le=1;le<=n;le++){
		for(int l=1;l+le-1<=n;l++){
			int r=l+le-1;
			if(abs(x[l]-x[r])<=d) dp[l][r]=1;
			for(int i=l;i<=r&&l+x[l]>=x[i];i++){
				dp[l][r]+=dp[l][i]+dp[i][r];
			}
			if(dp[l][r]==2) ans++;
		}
	}
	for(int i=0;i<=n;i++) {for(int j=0;j<=n;j++) cout<<dp[i][j];cout<<endl;}
	cout<<ans<<endl;
}

int main(){
	freopen("r","migrate.in",stdin);
	freopen("w","migrate.out",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
		f();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
