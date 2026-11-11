#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using i128=__int128;
using pii = pair<int, int>;
const int N=2e5+9,inf=1e9+9;
ll a[N];
int now[N], dis[N];
void solved(){
	int n;ll d;
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)now[j]=0,dis[j]=0;
		for(int j=i+1;j<=n;j++){
			ll x= a[j];

			if((i128)x-d<=(i128)a[i])dis[j]=1,now[j]=1;
			else{
				ll w=x-d;
				int pos=lower_bound(a+1,a+n+1,w)-a;
//				cout<<"xxx "<<pos<<' '<<w<<endl;
				if(now[pos]>2)now[j]=3;//无论如何不行了
				else{
					int vd=dis[pos];dis[j]=vd+1;
					while(dis[pos]==vd&&now[j]<=2){//n^3
						now[j]+=now[pos];
						pos++;
					}
					if(now[j]==2)ans++;
				}
			}
//			cout<<"test "<<x<<' '<<dis[x]<<' '<<now[x]<<endl;
		}
	}
	for(int i=1;i<=n;i++)a[i]=0;
	cout<<ans<<endl;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int num;cin>>num;
	int t;cin>>t;
	while(t--)
	solved();
	return 0;
}
/*
keep thinking  determined  calmed down!
显然我们需要一个 O(n) 的做法
简化一下题意
给定n 个岛屿 和一个距离 d
岛屿严格递增
两个岛屿之间若距离小于等于d，那么互相可以飞一次到达
两个岛屿的最短路径长度，记为最少飞行次数到达
若存在恰好两个情况使得两个岛屿可以通过最短路劲长度的飞行次数互相到达
此时我们认为出现了一个好的二元组
统计好的二元组的个数
我们先来看看先决条件
对于 N^2个二元组，我们先要知道彼此间的最短距离
然后才能求最短长度
所以条件相当严苛
两个节点可能互相不可达
一个结论：我们两个节点前后相互条约，肯定是选择d范围内，能走的最远
当一个 二元组 (u,v) 距离小于等于d 此时，绝对构成不了
如果构成，到底在暗示什么？
我原来选择的跳跃路径，当下改变其中一个最远节点退而求其次，此时，
仍能通过最短路径到达
原路径
a - b - c - d - e - f - g - h - j
新路径
a - b - c - D - e - f - g - h - j
改变，最多一个
所以，这个是满足单调性
若能通过三条及以上从 a - h ,那么必然的， 也能通过 3 条及以上 从 a - j
所以，从前往后枚举
向前考虑转移
我感觉是想不出来正解
我们考虑一下打暴力分
对于 O n^2 我们会发现
当前点往后跳能跳到的点，构成一个区间
而这个区间里的所有点对都不构成答案
然后从区间的右边节点开始考虑
若它到左边节点的距离，有超过三个是大于d的，此时无论如何不合法
若合法，我们还要记录当前路径数
即从1号节点到当前节点路径数
就是我们固定起始节点往右枚举的过程

我们不用去证明跳到右边再跳回左边
根本不可能的事情

大体思路
我们枚举每个起始节点
然后记录一个数组now 为当前路径数 还要记录一个 dis 为当前深度
路径数刚好为 2 的，合法二元组
我们对于每个节点作为起始节点

*/
