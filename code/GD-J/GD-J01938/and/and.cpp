#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n,m;
int a[maxn];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int dp[n+2][m+2]={0};
	//考虑前n个数，在选择m个数
	//的情况下，按位与的最大值 
	
	//初始化dp数组
	dp[1][1]=a[1];
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(j==1&&i!=1)dp[i][j]=max(dp[i-1][j],a[i]);
			if(j>i)dp[i][j]=-1;
			}
	}
	
	//状态转移
	for(int j = 2;j <= m;j ++){
		for(int i = j;i <= n;i ++){
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		} 
	}
	cout << dp[n][m];
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
