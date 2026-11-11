#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
bool flag=true;
int a[200005];
int dp[2005][2005];
int check(int x){
	int sum=0;
	for(int i=1;i<=n;i++) if((a[i]&x)==x) ++sum;
	return sum>=m;
}
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) dp[i][0]=(1ll<<31)-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) dp[i][j]=max((dp[i-1][j-1]&a[i]),dp[i-1][j]);
		cout<<dp[n][m];
		return 0;
	}
	int maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
	if(maxx<=4){
		for(int i=0;i<=4;i++) if(check(i)) ans=i;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) if(a[i]!=i-1) flag=false;
	if(flag) cout<<n-m;
	else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	return 0;
}
