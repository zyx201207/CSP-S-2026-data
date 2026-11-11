#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[9005][9005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z=max(z,a[i]);
		dp[1][i]=z;
	}
	if(m==1){
		cout<<z;
		return 0;
	}
	dp[1][1]=a[1];
	for(long long i=2;i<=n;i++){
		
		long long lx=max(i,m);
		for(long long j=lx;j>=2;j--){
			if(dp[j-1][i-1]==a[i]){
				dp[j][i]=dp[j-1][i-1];
			}
			long long l=0,p1=dp[j-1][i-1],p2=a[i],l1=0;
			while(p1!=0&&p2!=0){
				if(p1%2==1&&p2%2==1){
					l+=pow(2,l1);
				}else if(p1%2==0&&p2%2==0){
					l+=0;
				}
				l1++;
				p1/=2;
				p2/=2;
			}
			dp[j][i]=max(dp[j][i-1],l);
		}
	}
	cout<<dp[m][n]; 
	return 0;
} 
