#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005],dp[500005],yu[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	dp[1]=1;yu[1]=m;
	if(a[2]-a[1]>m){
		dp[2]=1;
		yu[2]=m;
	}
	else{
		dp[2]=2;
		yu[2]=m+a[1]-a[2];
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
//		if(m-(i-j+1)*a[i]+c[i]-c[j-1]<a[i]-a[j-1]){
//			dp[i]=i-j+1;
//			break;
//	    }
        if(yu[i-1]>=(a[i]-a[i-1])*dp[i-1]){
    	    yu[i]=yu[i-1]-(a[i]-a[i-1])*dp[i-1];
    	    dp[i]=dp[i-1]+1;
	    }
	    else{
		    int t=dp[i-1],need=(a[i]-a[i-1])*dp[i-1];
		    yu[i]=yu[i-1];
		    while(yu[i]<need){
			     yu[i]+=a[i]-a[i-t];
//			     need-=(a[i]-a[i-1]);
			     t--;
			     if(t==0) break;
		     }
		    if(t==0){
			    dp[i]=1;
			    yu[i]=m;
			    break;
		    }
		    yu[i]-=need;
		    dp[i]=t+1;
	    }
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
} 
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m;
//long long a[500005],c[500005],dp[500005];
//
//int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+1+n);
//	c[1]=a[1];
//	for(int i=2;i<=n;i++){
//		c[i]=c[i-1]+a[i];
//	}
//	dp[1]=1;
//	if(a[2]-a[1]>m){
//		dp[2]=1;
//	}
//	else dp[2]=2;
//	long long ans=0;
//	for(int i=2;i<=n;i++){
//		for(int j=i;j>=1;j--){
//			if(m-(i-j+1)*a[i]+c[i]-c[j-1]<a[i]-a[j-1]){
//				dp[i]=i-j+1;
//				break;
//	 	}
//		}
//		ans=max(ans,dp[i]);
//	}
//	cout<<ans<<endl;
//	return 0;
//} 
