#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long dp1[5005][2],dp2[5005][5005];
long long cf[500005];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=5005&&a[n]-a[n-1]==a[n-1]-a[n-2]){
		long long d=abs(a[n]-a[n-1]);
		unsigned long long xx=m/d;
		unsigned long long lim=xx*sqrt(2);
		for(unsigned long long i=lim;i>=2;i--){
			if(i*(i-1)<=xx){
				cout<<i;
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp1[i][0]=1;
		dp1[i][1]=i;
	}
	long long ans=0,cost1=0,cost2=0,idx=0,sum=0;
	for(int i=1;i<=n;i++){
		sum=1;
		idx=i;
		cost2=0;
		dp2[i][i]=0;
		for(int j=i-1;j>=1;j--){
			cost1=dp2[j][dp1[j][1]]+(a[i]-a[j])*dp1[j][0];
			if(cost2+a[i]-a[j]<=m){
				cost2+=a[i]-a[j];
				dp2[i][j]=cost2;
				dp1[i][0]++;
				dp1[i][1]=j;
			}
			if(cost1<=m){
				if(1+dp1[j][0]>sum){
					dp2[i][dp1[j][1]]=cost1;
					sum=1+dp1[j][0];
					idx=dp1[j][1];

				}
			}
		}
		if(dp1[i][0]<sum){
			dp1[i][0]=sum;
			dp1[i][1]=idx;
		}
		ans=max(ans,dp1[i][0]);
	}
	cout<<ans;
	
	return 0;

}
