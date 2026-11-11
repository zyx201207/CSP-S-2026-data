#include<bits/stdc++.h>
using namespace std;
vector<int> t[500005];
int n,m,w,a[500005],f[500005],q[500005],c[500005],ans[500005];
int dfs(int st)
{
	int sum=0;
	for(int i=0;i<t[st].size();i++) sum+=dfs(t[st][i]);
	sum+=c[st],ans[st]+=sum;
	return sum;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],q[a[i]]++;
	for(int i=n;i>=1;i--)
	{
		if(f[a[i]]) continue;
		f[a[i]]=1,c[a[i]]+=q[a[i]];
		if(i!=n) t[a[i+1]].push_back(a[i]);
	}
	dfs(a[n]);
//	for(int i=1;i<=n;i++) if(t[i].size()) cout<<t[i][0]<<" ";
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
/*
第一张与最后一张最后肯定会贡献 
n5e5 不可能一个一个遍历
如果第一张后面没有相同的，那么第二张也肯定会贡献，以此类推
如果有相同的那么相同的后面一张肯定也会贡献，以此类推
但是要处理5e5
第一张后面没相同的情况与下一个情况一样
有相同的情况和以相同开始的情况一样
考虑逆推一遍，如果是一个新的卡就把所有以这个卡位开始的都一次性加
还有90min，开始写 
会不会算重呢 
如果每个都是独立的呢，是否会超时
不会，总时间是O(n)的 
好像会被互不相同的点卡掉 
思路好像不是全对
怎么计数呢
记忆化？
但是依然过不去互不相同的点
逆推发现一个新的卡和前一种情况加上这个新卡是一样的
单独加上新的卡？
计算每个情况会被加几次？
互不相同段可以单独处理吗？
能否从A性质得出什么结论 
11:46 通过所有数据 
好神奇，我的做法理论应该乘出现次数 
没问题，已经乘了
%%%_ckx_ him_shu RedStoneShark OGcoder hsqi xxxasybt2023
祝自己15岁生日快乐 
*/
