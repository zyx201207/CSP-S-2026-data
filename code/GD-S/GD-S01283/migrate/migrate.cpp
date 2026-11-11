#include<bits/stdc++.h>
using namespace std;
const int maxn = 304;
using ll = long long;
ll a[maxn];
int dp[maxn][maxn][maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int len=2;len<=n;len++)
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if(a[j]-a[i]<=d){
					dp[i][j][1]++;
					continue;
				}
				int ln=j-i;
				for(int k=i+1;k<=j-1;k++)
					for(int l=1;l<=ln;l++)
						for(int r=1;r<=l-1;r++)
							if(dp[i][k][r] and dp[k][j][l-r]){
								ln=l;
								dp[i][j][l]+=(dp[i][k][r]*dp[i][k][l-r]);
							}
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=1;l<=j-i+1;l++){
					if(dp[i][j][l]==2)
						ans++;
					if(dp[i][j][l])
						break;
				}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2

4 2
1 2 3 4

5 2
1 2 3 4 5
*/
