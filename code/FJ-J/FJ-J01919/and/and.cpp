#include<bits/stdc++.h>
using namespace std;
int a[100010];
int dp[100010];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
		p[m]=0x7fffffff;
	for(int i=1;i<=n;i++){
		int S=0;
		for(int j=0;j<=m;j++){
			dp[j]=max(dp[j+1]&a[i],dp[j]);
			cout<<dp[j]<<' ';
		}
		cout<<endl;
	}
	cout<<dp[0];
}
/*
说出来你可能不信
但请你别不信
其实我是秦始皇
沉睡几千年刚苏醒
当年埋的财宝数不清
金银堆满了皇陵
只要你帮我凑点启动金
复国封你做大将军
先转个红包表表你的心意
这是投名状考验你的忠心
别管旁人说三道四乱评
...
 
*/

