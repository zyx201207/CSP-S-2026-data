#include<bits/stdc++.h>
using namespace std;
//migrate
int n;
long long d;
long long x[3300];
long long dp[3300][3300];
bool min_len(int r,int y){
	memset(dp,0,sizeof(dp));
	dp[r][0]=1;
	for(int i=r;i<y;i++){
		for(int j=i+1;j<=y;j++){
			if(x[j]-x[i]<=d){
				for(int k=0;k<=i-r;k++){
					if(dp[i][k])dp[j][k+1]+=dp[i][k];
				}
			}
		}
	}
//	cout<<r<<" - "<<y<<endl; 
//	for(int i=r;i<=y;i++){
//		cout<<"\t"<<i<<" : \n";
//		for(int j=0;j<=i-r;j++){
//			cout<<"\t\t"<<j<<" : "<<dp[i][j]<<endl;
//		}
//	}
	for(int i=1;i<=y-r;i++){
		if(dp[y][i]){
			if(dp[y][i]==2)return 1;
			return 0;
		}
	}
	return 0;
}
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(min_len(i,j)){
				ans++;
//				cout<<i<<" -> "<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}

