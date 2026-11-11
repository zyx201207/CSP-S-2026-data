#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],dp[30][30],res,mxx=-1,isA=1,isC=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	res=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		res&=a[i];
		mxx=max(mxx,a[i]);
		if(a[i]&a[i-1]!=0)isA=0;
		if(a[i]>=4)isC=0;
	}
	if(m==1)cout<<mxx<<'\n';
	else if(n==m)cout<<res<<'\n';
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans<<'\n';
	}else if(isA||isC){
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<'\n';
	}else if(n<=20){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			dp[i][1]=mx;
		}
		for(int k=2;k<=m;k++){
			for(int i=k;i<=n;i++){
				dp[i][k]=max(dp[i-1][k-1]&a[i],dp[i-1][k]);
			}
		}
		cout<<dp[n][m]<<'\n';
	}
	return 0;
}
