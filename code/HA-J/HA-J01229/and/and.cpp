#include<bits/stdc++.h>
using namespace std;
const int N=2005;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m;
long long a[N],ans=0,dp[N][N][2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();m=read();
	int flag1=1,flag2=1;
	if(n<=2000) flag1=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(flag1&&(a[i]+1)%2!=0) flag1=0;
		if(flag2&&a[i]!=i-1) flag2=0;
	}
	sort(a+1,a+1+n);
	if(flag1){
		cout<<a[n+1-m];
		return 0;
	}
	if(flag2){
		if(m>(n/2)) cout<<0;
		else if(m==1) cout<<a[n];
		else if(m==2) cout<<a[n-1];
		else if(m%2==1) cout<<a[n-m];
		else cout<<a[n-m+1];
		return 0;
	}
	for(int k=1;k<=m;++k)
		dp[0][k][1]=dp[0][k][0]=0;
	for(int i=1;i<=n;++i)
		dp[i][1][1]=a[i];
	for(int i=2;i<=n;++i){
		for(int k=2;k<=min(i,m);++k){
			dp[i][k][1]=max(dp[i-1][k-1][0]&a[i],dp[i-1][k-1][1]&a[i]);
			dp[i][k][0]=max(dp[i-1][k][1],dp[i-1][k][0]);
		}
	}
	cout<<max(dp[n][m][1],dp[n][m][0]);
	return 0;
}

