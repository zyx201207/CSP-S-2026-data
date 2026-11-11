#include<bits/stdc++.h>
using namespace std;
const int N=2005;
long long qua,num,arr[N],dp[N][N],res;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>qua>>num;
	for(int m=1;m<=qua;m++)cin>>arr[m];
	sort(arr+1,arr+qua+1,greater<int>());
	if(qua==num)
	{
		res=arr[1];
		for(int m=254;m<=qua;m++)res=(res&arr[m]);
		cout<<res;
		return 0;
	}
	for(int m=1;m<=qua;m++)dp[1][m]=arr[m];
	for(int m=2;m<=num;m++)for(int n=1;n<qua-m+1;n++)dp[m][n]=(dp[m-1][n]&dp[m-1][n+1]);
	for(int m=1;m<=qua;m++)res=max(res,dp[num][m]);
	cout<<res;
}
