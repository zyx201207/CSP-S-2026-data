#include<bits/stdc++.h>
using namespace std;
long long m,dp[500005],a[500005],min1=-1e6,sum1=-1e7,max1=-1e6,sum=1;
int n;
bool p=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	dp[2]=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		cin>>a[i];
		dp[i]=abs(a[i]-a[i-1]);
		max1=max(max1,a[i]);
		min1=min(min1,a[i]);
		if(dp[i]!=dp[2]) p=1;
	}
	if(p==0){
	    		for(int j=1;j<=n;j++){
	    			for(int k=2;k<=j+1&&dp[k]*j<=m;k++){
	    				sum++;
	    			      m-=dp[k]*j;
					}
				}
				if(m!=0&&n%m==0){
					cout<<sum;
				}else{
					cout<<sum-1;
				}
	}else{
		sort(a+1,a+n+1);
			for(int i=min1+1;i<=max1;i++){
				sum=0;
				int h=m;
				for(int j=n;j>=1;j--){
					if(a[j]<=i&&h>=i-a[j]){
						h=h-(i-a[j]);
						sum++;
					}
				}
				if(sum>sum1){
					sum1=sum;
				}
			}
			cout<<sum1;
	}
	return 0;
}

