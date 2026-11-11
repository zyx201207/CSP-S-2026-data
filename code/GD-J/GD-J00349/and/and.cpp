#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[2000005];
int dp[2005][2005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		int maxx=0;
		int cnt=1;
		for(int RP=1;RP<=31;RP++)cnt*=2;
		cnt-=1;
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=n;j++){
				if(j!=i){
					cnt=cnt&a[j];
				}
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][k]&a[j]);
			}
			cout<<dp[i][j]<<endl;
		}
		cout<<endl;
	}
	cout<<dp[m][n];
	return 0;
}
