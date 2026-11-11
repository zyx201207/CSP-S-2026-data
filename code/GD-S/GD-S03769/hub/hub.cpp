#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5+5;

/*
题意:
n 个节点的树 T, 在其上选 k 个点为科研基地, 如果将这些点看作图，则这张图形成不超过两个连通块
现在定义 d 表示通勤距离, d 的计算方式如下 
- d 在科研基地中 -> d = 0
- d 不在科研基地中 -> d = 离他最近的科研基地的距离
再定义 D 为通勤半径, D 的计算方式为 max(i=1~n) d(i)
求通勤半径的最小值 
*/  

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
} 
