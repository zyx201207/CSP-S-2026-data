#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;long long a[n];for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+n+1);
	int q=0;bool k=1,h=1;
	for(int i=2;i<n;i++){
		if(a[i-1]-a[i]!=a[i]-a[i+1]) k=0;
		if(a[i]!=a[i]-1||a[i]!=a[i+1]) h=0;
		if(!(k&&h)) break;
	}
	if(h){
		cout<<n;return 0;
	}
	if(k){
		int d=a[2]-a[1];
		cout<<ceil((sqrt(1+4*m/d)+1)/2);
		return 0;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int dp[m+3];
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=i;j++){
			for(int f=m;f>=(a[i]-a[j]);f--) dp[f]=max(dp[f],dp[f-(a[i]-a[j])]+1);
		}
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx+1;
	return 0;
}
