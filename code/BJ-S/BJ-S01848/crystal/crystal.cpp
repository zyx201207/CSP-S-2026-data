#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[500005],a[500005],minn[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		minn[i]=1000000000005;
		//cout<<i<<"/"<<n<<" ";
	}
	//cout<<n;
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	//printf("%lld\n",n);
	dp[2]=a[2]-a[1];
	dp[1]=0;
	minn[1]=0;
	for(int i=2;i<n;i++)
		for(int j=i;j>=1;j--){
			//cout<<j+1<<" "<<dp[j]+j*(a[i+1]-a[i])<<" "<<minn[j+1]<<endl;
			dp[j+1]=dp[j]+j*(a[i+1]-a[i]);
			minn[j+1]=min(minn[j+1],dp[j+1]);
		}
	int maxx=0;
	//cout<<n<<endl;
	while(66){
		//cout<<minn[maxx]<<" ";
		if(maxx>=n)break;
		if(m>=minn[maxx+1]){
			maxx++;
			//cout<<minn[maxx]<<" "<<maxx<<"  ";
		}else break;
	}
	//cout<<endl;
	cout<<maxx;
	return 0;
}
