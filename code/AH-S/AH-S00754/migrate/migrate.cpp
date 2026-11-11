#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d; 
long long a[2000005];
bool p[5005][5005];
long long dp[305][305][305];//从i到j，长度为k的路径有几条 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c>=0 && c<=10){
		while(t--){
			memset(p,false,sizeof p);
			memset(dp,0,sizeof dp);
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						p[i][j]=true;
						dp[i][j][1]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int l=i;l<=j;l++){
							if(p[l][j])dp[i][j][k]+=dp[i][l][k-1];
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(dp[i][j][k] && dp[i][j][k]!=2)break; 
						if(dp[i][j][k]==2){
							ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
