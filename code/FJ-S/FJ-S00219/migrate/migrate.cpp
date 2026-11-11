#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int c,t;
int n;
long long d;
long long dp[5005][5005];
long long cnt[5005][5005];
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate1.in","r",stdin);
	cin>>c>>t;
	if(c<=10){//»ò¸Ä10 
		while(t--){
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int len=1;len<=n;len++){
				for(int i=1;i+len-1<=n;i++){
					int j=i+len-1;
					if(abs(x[i]-x[j])<=d){
						dp[i][j]=1;
						cnt[i][j]=1;
						continue;
					}
					for(int k=i+1;k<j;k++){
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
					}
					if(dp[i][j]<=2e12){
						for(int k=i+1;k<j;k++){
//							if(i==1&&j==5){
//								cout<<k<<" ";
//							}
							if(dp[i][k]+dp[k][j]==dp[i][j]){
								cnt[i][j]+=cnt[i][k]*cnt[k][j];
								if(cnt[i][j]>=1e8) cnt[i][j]=1e8;
							}
						}
//						if(i==1&&j==5){
//							cout<<endl;
//						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
//					cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<cnt[i][j]<<endl;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
//	if(11<=c&&c<=12){
//		while(t--){
//			cin>>n>>d;
//			for(int i=1;i<=n;i++){
//				cin>>x[i];
//			}
//			int cha=x[n]-x[n-1];
//			
//		}
//		return 0;
//	}
	if(13<=c&&c<=14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long ans=0;
			for(int i=4;i<=n;i++){
				if(abs(x[i-3]-x[i])>d){
					if((abs(x[i-2]-x[i-3])<=d&&abs(x[i-2]-x[i])<=d)&&(abs(x[i-3]-x[i-1])<=d&&abs(x[i]-x[i-1])<=d)){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
//0~16~32~48?
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
6

13 2
8 5
1 2 4 5 7 8 9 10
6 6
1 4 5 6 9 11
*/
