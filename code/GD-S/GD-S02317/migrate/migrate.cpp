#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int x[5005];
int dp1[5005][5005];
int dp2[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp1[i][j]=0x7ffffff;
				dp2[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp1[i][i]=0;
			dp2[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					dp1[i][j]=1;
					dp2[i][j]=1;
				}
			}
		}
		for(int len=1;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				for(int j=i;j<=i+len-1;j++){
					dp1[i][i+len-1]=min(dp1[i][i+len-1],dp1[i][j]+dp1[j][i+len-1]);
				}
			}
		}
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				for(int j=i+1;j<i+len-1;j++){
					if(dp1[i][j]+dp1[j][i+len-1]==dp1[i][i+len-1]){
						dp2[i][i+len-1]+=dp2[i][j]*dp2[j][i+len-1];
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				//cout<<i<<" "<<j<<" "<<dp2[i][j]<<"\n";
				if(dp2[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}  
