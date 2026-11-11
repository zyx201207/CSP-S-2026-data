#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,d;
int pos[5000010];
int sum[5000010];
int dp[5010][5010];
int ss[5010][5010];
//int tr[5000010];
//int rabbit(int x){
//	return x&(-x);
//}
//void add(int pos,int dat){
//	while(pos<=n){
//		tr[pos]+=dat;
//		pos+=rabbit(pos);
//	}
//}
//int query(int r){//²î·Ö 
//	int sum1=0;
//	while(r>=1){
//		sum1+=tr[r];
//		r-=rabbit(r);
//	}
//	return sum1;
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		for(int i=1;i<=n;i++){
			sum[i]=pos[i]-pos[1];
		}
//		for(int i=1;i<=n;i++){
//			cout<<sum[i]<<" ";
//		}
//		cout<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dp[i][j]=INT_MAX/2;
				ss[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&sum[j]-sum[i]<=d;j++){
				dp[i][j]=dp[j][i]=1;
				ss[i][j]=ss[j][i]=1;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;sum[j]-sum[i]<=d;j++){
//				
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dp[i][j]<<" ";
//			}cout<<endl;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//			}
//		}
		for(int k=1;k<=n;k++){//ÖÐ 
			for(int i=1;i<=n;i++){//Æð 
				for(int j=1;j<=n;j++){//ÖÕ 
					if(dp[i][j]==dp[i][k]+dp[k][j]){
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
						ss[i][j]+=ss[i][k]*ss[k][j];
					}else if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
						ss[i][j]=1;
					}
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<ss[i][j]<<" ";
//			}cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(ss[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
