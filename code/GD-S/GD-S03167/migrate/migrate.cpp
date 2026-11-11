#include<bits/stdc++.h>
using namespace std;
const int N=3005;
const long long inf=1e18;
int c,t,n;
long long a[N];
long long d;
long long g[N][N];
long long dp[N],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=inf;
			}
			g[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					g[j][i]=g[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
//				cout<<"最短路："<<j<<' '<<i<<' '<<g[j][i]<<endl;
				for(int k=j+1;k<=i;k++){
					dp[k]=0;
				}
				dp[j]=1;
				for(int k=j+1;k<=i;k++){
					for(int pre=j;pre<k;pre++){
						if(a[k]-a[pre]<=d){
							if(g[j][pre]+1==g[j][k]){
								dp[k]+=dp[pre];
							}
						}
					}
//					cout<<"数量："<<j<<' '<<i<<' '<<k<<' '<<dp[k]<<endl;
				}
				if(dp[i]==2){
					ans++;
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
fc migrate.out ex3.txt
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0
1

*/
