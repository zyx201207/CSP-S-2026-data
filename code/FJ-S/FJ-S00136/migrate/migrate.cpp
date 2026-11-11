/*LA FLAMME SURVIT SOUS LA PLUIE DEPUIS TANT D'HIVERS
LE SANG VERSÉ LIE NOS ÂMERE FIÈRES
LA CROIX DE LORRAINE NOUS ÉCLAIRE
VER PARIS ET VER LA MER*/
#include<bits/stdc++.h>
using namespace std;
void rp(int rp){
	while(1)rp++;
}
int n,d,x[5013],dp[5078][5091],ans;
void work(){
	ans=0;
	memset(dp,0,sizeof dp);
	cin>>n>>d;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)dp[i][j]=0;
		for(int j=i+1;j<n;j++){
			int m=0x7fffffff;
			for(int k=0;k<n;k++)if(dp[j][k]>0)m=k;
			if(m!=0x7fffffff)for(int k=j+1;k<n;k++)if(x[k]-x[j]<=d)dp[k][m+1]=dp[j][m];
		}
		for(int j=i+1;j<n;j++)for(int k=0;k<n;k++)if(dp[j][k]==2){
			ans++;
			goto f;
		}
		f:
		ans;
	}
	cout<<ans<<endl;
	return;
}
int main(){
	int t;
	cin>>t>>t;
	while(t--)work();
	return 0;
}

