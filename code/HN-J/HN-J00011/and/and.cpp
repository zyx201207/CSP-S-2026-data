#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int dp[200010][2];
	int a[200010],n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=max(dp[i][0],dp[i][1]+dp[i][1]|a[i]);
		dp[i][0]=dp[i][1];
	}
	cout<<dp[n][1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}//哦 
//善良的数据范围 
//10个测试点都是n <= 2000 
//直接暴力有50分！ 
//O(n^2log n)都行 
//wow 这题的暴力貌似需要O(n^m)的雷霆时间 大概是2000^2000…… 
//虽然好像正解是dp 
//先打暴力 后dp 
//Update 10:55 暴力想了个棍木出来 
//直接打正解吧 
//瞎写了一个
//估计能拿棍木分 
//100+56+0+0=156=2==AFO 

















/*
闲话
这个机房里面是AMD Ryzen 3 3200G
差不多和上次的 i3 10100差不多
但是频率低了一大截
RAM也只有6GB
最高也只有3.85GHz
4C4T
给到拉完了
显示器只有1K
还屎黄屎黄的
拉完了 
*/
