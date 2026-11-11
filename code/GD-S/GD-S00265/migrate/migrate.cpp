#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=2e6+5;
int c,t;
int a[maxn];
int n,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		//if(c>=1&&c<=6){
			int num=0;
			int dp[n+5][n+5];
			for(int i=1;i<n;i++){
				memset(dp,0,sizeof(dp));
				for(int j=0;j<=n;j++) dp[j][i]=1;
				for(int j=i;j<n;j++){
					for(int k=j+1;k<=n;k++){
						//j->k
						if(a[k]-a[j]>d){
							break;
						}
						
						for(int l=0;l<=n;l++)dp[l+1][k]+=dp[l][j];
					}
				}
				
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(dp[k][j]==2){
							num++;//cout<<i<<' '<<j<<' '<<k<<'\n';
							break;
						}
						if(dp[k][j]!=0){
							break;
						}
					}
				}
				
			}
			cout<<num<<'\n';
		//}
		
		
	}
	
	return 0;
}
/*

 O(n^4)


*/
 
