#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e4+10;
int n,m,ans,sum,maxn;
int a[N],dp[M][M];
bool vis[N];
bool fa=1,fb=1;
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i==1) sum=a[i];
		int k=log2(a[i]);
//		if(a[i]!=i-1) fb=0;
		if(a[i]+1!=pow(2,k+1)) fa=0;
		maxn=max(maxn,a[i]);
		sum=sum and a[i];
		dp[i][1]=maxn;
	}
//	cout<<fa<<" "<<fb<<"\n";
	if(fa==1) 
	{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
//	int k=log2(n);
//	if(fb==1&&n==pow(2,k)) 
//	{
//		
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			//cout<<"dp[i:"<<i<<"][j:"<<j<<"]:"<<dp[i][j]<<"\n";
		}
	}
	cout<<dp[n][m];
	return 0;
}
