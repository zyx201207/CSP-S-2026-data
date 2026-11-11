#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
long long czhi[1000005];
long long jueduizhi(long long a,long long b){
	if(b>a) swap(a,b);
	return (a-b);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	long long ans=1;
	cin>>n>>m;
	for(int i1=1;i1<=n;i1++){
		cin>>dp[i1];
	}
	sort(dp+1,dp+n+1);
	while(1){
		long long xuhao=0x3f;
		czhi[1]=0x3f;
		long long minc1=czhi[1];
		long long c=minc1;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
		    	if(i==j) continue;
			    czhi[i]=min(czhi[i],jueduizhi(dp[j],dp[i]));
		    }
			
			minc1=min(minc1,czhi[i]);
		    if(minc1!=c) {
		    	c=minc1;
		    	xuhao=i;
			}
	    }
	    if(minc1==0) {
	    	ans++;
	    	dp[xuhao]=0x3f;
	    	continue;
		}
	    if(minc1<=m){
	    	m-=minc1;
	    	ans++;
	    	if(dp[xuhao]+minc1==dp[xuhao++]){
	    		xuhao--;
	    		dp[xuhao]+=minc1;
			}
			else dp[xuhao]-=minc1;
		}
		if(minc1>m) break;
	}
	cout<<ans;
    return 0;
}
