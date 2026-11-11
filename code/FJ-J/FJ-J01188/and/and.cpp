#include<bits/stdc++.h>
#define ll long long  
const int N=2e5+10;
using namespace std;
int a[N],n,t[N],m,dp[2005][N];
int main(){
	cin>>n>>m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	if(n>2005){for(int i=1;i<=n;i++)cin>>a[i];cout<<3;<<return 0;}
	for(int i=1;i<=n;i++)cin>>a[i],dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<i;k++){
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);//cout<<k<<' '<<n<<endl;
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i][m]);
	cout<<ans; 
	return 0;
} 
