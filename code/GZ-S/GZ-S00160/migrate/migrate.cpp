//GZ-S00160 贵阳市第十七中学 汪夏乐 
#include<bits/stdc++.h>
using namespace std;
long long a[2010];
long long dp[2010][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	while(T--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int k=0;k<n;k++){
			memset(dp,0x3f,sizeof(dp));
			dp[k][0]=0;
			for(int i=k;i<n;i++){
				int j=i+1;
				for(;j<n;j++){
					if(a[j]-a[i]>d){
						j=j-1;
						break;
					}
				}int mnn=INT_MAX,ans=0;
				for(int l=j;l>i;l--){
					if(mnn>dp[l][0]){
						mnn=dp[l][0]+1;
						ans=1;
					}else if(mnn==dp[l][0]){
						ans+=dp[l][1];
					}
				}
				dp[j][0]=mnn;dp[j][1]=ans;
			}
			for(int i=k;i<n;i++){
				cout<<dp[i][0]<<" "<<dp[i][1]<<"   ";
				if(dp[i][1]==2){
					cnt++;
				}
			}
			cout<<endl;
		}
		cout<<cnt;
		}
	
	return 0;
}
