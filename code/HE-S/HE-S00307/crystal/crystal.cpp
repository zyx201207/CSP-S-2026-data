#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N],c[N],t;
int n,dp[5005][5005],ans;
bool b,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]!=a[i-1])
				b=true;
		}
	}
	if(!b){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=abs(a[i+1]-a[i]);
		if(i!=1){
			if(c[i]!=c[i-1])
				f=true;
		}
	}
	if(!f){
		m/=c[1];
		while(m>0){
			m-=++ans;
		}
		cout<<1<<' '<<min(n,++ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		dp[i][i]=0,dp[i][i+1]=c[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[j-1][j]*(j-i)+dp[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]<=m)
				ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
