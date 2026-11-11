#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5007;
const int inf=INT_MAX;
int c,t;
int n;
ll d;
ll x[N];
ll dp[N][N];
ll tp[N][N];
int dis[N];
int nis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			dis[i]=lower_bound(x+1,x+n+1,x[i]+d)-x;
			nis[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=dis[i];j++){
				dp[i][j]=2;
				tp[i][j]=1;
			}
		}
		for(int i=d+1;i<=n;i++){
			for(int j=1;i+j<=n;j++){
				tp[j][i+j]=0;
				dp[j][i+j]=inf;
				for(int k=nis[i+j];k<=dis[j];k++){
					dp[j][i+j]=min(dp[j][k]+dp[k][i+j]-1,dp[j][i+j]);
				}
				for(int k=nis[i+j];k<=dis[j];k++){
					if(dp[j][k]+dp[k+1][i+j]-1==dp[j][i+j]){
//						cout<<tp[j][k]<<" "<<tp[k][i+j];
						tp[j][i+j]+=tp[j][k]*tp[k][i+j];
					}
				}
				//cout<<tp[j][i+j]<<" "<<dis[j]<<" "<<nis[i+j]<<"  "<<j<<" "<<i+j<<" "<<dp[j][i+j]<<endl;
				if(tp[j][i+j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

