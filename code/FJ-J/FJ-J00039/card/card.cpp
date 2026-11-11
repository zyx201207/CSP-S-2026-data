#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll a[N],cnt[M],n,m;
ll d[M];
ll nxt[M];
ll now[M];
bool A=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			A=0;
		}
	}
	if(A&&n>=5005)
	{
		for(int i=1;i<=n;i++)
		{
			d[a[i]]+=1;
		}	
		ll sum=0;	
		for(int i=1;i<=m;i++)
		{
			sum+=d[i];
			cout<<sum<<' ';
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		nxt[i]=i;
		if(now[a[i]])
		{
			nxt[i]=now[a[i]];
		}
		now[a[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		while(nxt[i]!=i&&nxt[i]!=nxt[nxt[i]]&&a[nxt[nxt[i]]]==a[i])
		{
			nxt[i]=nxt[nxt[i]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			j=nxt[j];
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
/*
1 2 1 3

i<=j&&a[i]>=a[j]

1


1...1.....1.......1

第一次出现的位置
最后一次出现的位置 



1 
1：1 
2：
3： 
点数都是1到m之间的整数
点数都出现至少一次
n局相互独立的游戏
第i(1≤i≤n)局中，他跳过前i-1张牌，依次打出第i张到第n张
牌，这些牌的点数依次为ai,ai+1,...,an
每局开始前，他会将所有牌按原顺序放回牌堆
打出一张点数为k的牌时
若没有，放到最右侧
否则，收走点数为k的牌及其右侧的所有牌，再把这张牌放在最右端。
每个i=1,2,...,m，在所有n局游戏中，有多少
局结束时桌面上留有点数为i的牌

n<=5e5+5
m<=3e5+5

N
*/ 
