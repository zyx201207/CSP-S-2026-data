#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,js;
int a[5005];
int dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ttt=0;ttt<t;ttt++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][i-1]=1;
		}
		for(int len=1;len<=n;len++){
			for(int l=1;l<=n-len;l++){
				int r=l+len;js=0;
				dp[l][r]=r-l;
				for(int f=r;f>=l;f--){
					if(a[r]-a[f]>d){
						break;
					}
					if(dp[l][f]+1<dp[l][r])dp[l][r]=dp[l][f]+1,js=1;
					else if(dp[l][f]+1==dp[l][r])js++;
				}
				if(js==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
