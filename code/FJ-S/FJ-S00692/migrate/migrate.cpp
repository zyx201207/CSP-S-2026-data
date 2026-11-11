#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005],dp[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=6){
			int ans=0;
			for(int u=1;u<=n;u++){
				memset(dp,0,sizeof(dp));
				dp[u][0]=1;
				for(int k=1;k<=n;k++){
					long long s=0;
					int p=u;
					for(int v=u+1;v<=n;v++){
						s+=dp[v-1][k-1];
						while((a[v]-a[p])>d&&(p<=n)){
							s-=dp[p][k-1];
							p++;
						}
						dp[v][k]=s;
					}
				}
				for(int v=u;v<=n;v++){
					for(int k=0;k<=n;k++){
						//cout<<dp[v][k]<<' ';
						if(dp[v][k]>0){
							if(dp[v][k]==2) ans++;
							break;
						}
					}
					//cout<<'\n';
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
