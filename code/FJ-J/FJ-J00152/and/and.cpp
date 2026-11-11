#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005][2],dp[1000005],x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i][1]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[2]<(a[i][1] & a[j][1])){
				x=i;
				y=j;
				dp[2]=(a[i][1] & a[j][1]);
			}
		}
	}
	a[x][2]=1;
	a[y][2]=1;
	for(int i=3;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][2]==0){
				if(dp[i]<(dp[i-1] & a[j][1])){
					x=j;
					dp[i]=(dp[i-1] & a[j][1]);
				}
			}
		}
		a[x][2]=1;
	}
	cout<<dp[m];
	return 0;
}
