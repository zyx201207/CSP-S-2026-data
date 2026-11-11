#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;//暴力 
	char s[1000005];
	int len=0,a;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s[len++]=c;
	}
	char t[1000005];
	for(int i=len-1,j=0;i>=0,j<len;i--,j++)
		t[i]=s[j];
	int ans=0;
	if(t==s) return printf("0"),0;
	else
		for(int i=0;i<(len+1)>>1;i++)
			if(t[i]!=s[i]) ans++;
	printf("%d",ans);
//	int n;
//	cin>>n;
//	long long t[200010];
//	char c[200010];
//	int a;
//	char b;
//	t[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&a);
//		cin>>b;
//		t[i]=t[i-1]+(1ll*a);
//		c[i]=b;
//	}
//	n=(n+1)>>1;
//	long long ans=0;
//	for(int i=1,j=2*n;i<=n,j>=n;i++,j--)
//	{
//		if(c[i]==c[j]) continue;
//		if(t[i]==t[j]&&c[i]!=c[j]) ans+=(t[i]-t[i-1]);
//		if(t[i]!=t[j]&&c[i]!=c[j]) ans+=min(abs(t[i]-t[i-1]),abs(t[j]-t[j+1]));
//	}
//	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//Update 9:16 酣畅淋漓的打了一把小恐龙 score2137 
//哦天哪t2的题面让我两眼一黑 
//先吃个部分分 
//暴力还原字符串
//68pts 
//最长2*1e5*5*1e2=1e8
//允许暴力 
//Update 9:47
//哦不暴力只有56pts
//吃空间太大了 
//只能开出2个1e6的char组
// 欸(手指上翘) 想出来个疑似正解 实现一下看看 
//既然不能直接还原字符串 
//那就只统计长度 
//然后砍两半 
//比较前后两段组成回文  
//区间化 区间l~r之间的都是x 
//2*1e5的char 标记区间字符 
//一个nailong数组记录区间变化位置 
//nailong[i]记录第i个变化的端点位置 
//开个nai long总不能RE了 
//如何比较？
//额 
//这是二分吗
//我想的是模拟的思路 
//可 
//将区间不同字符的累加进ans 
//till 10:06 深度思考结束 
//Update 10:27
//ans累加了2遍长度 
//所以也要砍半 
//Update Ohhh Nooooo
//正解没写出来 
//不知有多少分 
//只能拿暴力先顶上 
//看t3t4有没有好拿的部分分 
