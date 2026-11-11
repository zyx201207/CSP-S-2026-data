#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N];
bool val[N];
int ex[N];
int nxt[N];
int ans[N];
unordered_map<int,int> mp; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=n;i>0;--i)
	{
		ex[i]=1;
		if(mp[a[i]])
		{
			nxt[i]=mp[a[i]];
		}
		else
		{
			nxt[i]=i+1;
			mp[a[i]]=i;
			val[i]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(val[i]) ans[a[i]]+=ex[i];
		ex[nxt[i]]+=ex[i];
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
//注意到
//本轮游戏的第一张牌一定会保留
//后方有与第一张牌同值的牌时
//前面所有牌一定消除
//O(n)可以计算每一次保留的点数
//题目要求每个点数有几次保留
//把游戏倒过来n->1
//不难发现，即每次增加第一张牌
//故每次相比上次最多增加一个值
//记当前值a[i],当前数集s[i] 
//由于消除机制
//如后方(i<j<=n)有a[j]==a[i]
//则a[k](i<=k<j)全部消除
//即s[i]=s[j]
//否则相当于增加a[i]一个值
//s[i]=s[i+1]+a[i]
//记录s需要大量复制，不可行 
//想到使用指针
//用nxt[i]表示继承的数集位置(即j)
//val[i]表示当前是否增加
//从1->n遍历
//累加答案 
