#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  c,t,n,d,x[2500000],dp[6000][6000],mi[6000][6000];
void trust(){
	cin>>n>>d;
	ll coop=0;
	memset(dp,0,sizeof(dp));
	memset(mi,0,sizeof(mi));
	memset(x,0,sizeof(x));
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		dp[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d&&j!=i){
				dp[i][j]=1;
				mi[i][j]=1;
				continue;
			}
			else {
				dp[i][j]=1e10;
			}

			for(ll k=i+1;k<j;k++){
				if((x[j]-x[k])<=d&&(x[k]-x[i])<=d){
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					
					dp[i][j]=dp[i][k]+dp[k][j];
					if(mi[i][j]==2){
						coop--;
						mi[i][j]=1;
					}
				}
				if(dp[i][j]<dp[i][k]+dp[k][j]) {
					
					continue;
				}
				if(dp[i][j]==(dp[i][k]+dp[k][j])){
					mi[i][j]++;
					if(mi[i][j]==2){
						coop++;
					}
					if(mi[i][j]==3){
						coop--;
					}
				}
				
			}
			}
		}
	}
	cout<<coop<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		trust();
	}
	
	return 0;
}
