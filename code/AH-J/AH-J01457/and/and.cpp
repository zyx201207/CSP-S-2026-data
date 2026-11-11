#include "bits/stdc++.h"
using namespace std;

long long dp[5005][5005],n,m,a[500005],maxn=-1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}
	
	else if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s<<endl;
		return 0;
	}
	
	else if(m==2){
		long long s=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s<<endl;
		return 0;
	}
	
	else if(m==n-1){
		long long s=a[2];
		for(int i=3;i<=n;i++) s&=a[i];
		long long ans=s;
		for(int i=1;i<=n;i++){
			s=a[1];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				s&=a[i];
			}
			ans=max(ans,s);
		}
		cout<<ans<<endl;
		return 0;
	}
	
	for(int i=0;i<=n;i++) dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i*1ll,m);j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],(dp[i-1][j-1]&a[i])));
		}
	}
	long long ans=INT_MIN;
	for(int i=m;i<=n;i++) ans=max(ans,dp[i][m]);
	cout<<ans<<endl;
	return 0;
}

