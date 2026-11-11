#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int maxdp=-1,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			s[0]=a[1];
		}
		s[i]=a[i]&s[i-1];
		maxn=max(maxn,a[i]);
	}

	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<s[n];
		return 0;
	}
	else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1){
	
	}
	else{
		for(int i=1;i<=n;i++){
			dp[i]=max(a[i],dp[i-1]);
		}
		for(int i=2;i<=m;i++){
			for(int j=n;j>=i;j--){
				dp[j]=dp[j-1]&a[j];
			}
		}
		for(int i=m;i<=n;i++){
			maxdp=max(dp[i],maxdp);
		}
		cout<<maxdp;
		return 0;
	}
	return 0;
}
