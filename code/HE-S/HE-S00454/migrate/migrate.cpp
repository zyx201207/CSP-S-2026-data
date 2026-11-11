#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num,minn;
};
int c,t,n,d;
int a[50010];
Node dp[10010][10010];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j].num=0;
				dp[i][j].minn=100010;
			}
			dp[i][i].minn=0;
			dp[i][i].num=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]>d){
						break;
					}
					if(dp[i][j].minn>dp[i][k].minn+1){
						dp[i][j].num=dp[i][k].num;
						dp[i][j].minn=dp[i][k].minn+1;
					}
					else if(dp[i][j].minn=dp[i][k].minn+1){
						dp[i][j].num+=dp[i][k].num;
					}
				}
				if(dp[i][j].num==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
