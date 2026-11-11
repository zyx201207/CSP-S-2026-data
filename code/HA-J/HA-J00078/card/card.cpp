#include<bits/stdc++.h>
using namespace std;
#define int long long
//1h到手300pts，还是很稳的
//哦哦哦这是那个接竹杆，我挺喜欢玩的
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M]; 
//考虑一张牌在什么情况下能被留下了，只考虑打出的牌中
//那就是对于这个颜色的最后一张牌，他不在任何一个以两个颜色相同牌为左右端点的区间内
//不对不对，会不会出现说有一些消除帮这张牌消除了前面的障碍使得它能存活下去，这显然是可能的
//考虑倒序处理或者正难则反
stack<int>st;
bool vis[N]; 
//不对不对也许我应该换一个思路
//不要想太难，这题应该就是个中位绿
//首先每个颜色的牌能否留下一定是跟他最后一张牌有关，如果最后一张牌会被后面的某些区间删掉，那这个颜色一定不行
int lst[M];
//额现在有了基础的代码，但复杂度应该是错的，容易卡到O(n^2)，考虑优化 
//感觉这个做法是比较有前途的，接着想 
//所以这是一个图论题？一条长为n的链加上m个菊花，然后求一些神秘路径 
//感觉可以再正难则反一下然后倍增优化？
//哦我们可以直接向后面那个点连边然后统计一下子树大小
//哎我为啥没有c++14 
vector<int>vt[N]; 
int to[N],siz[N];
void dfs(int u){
	siz[u]=vis[u]=1;
	for(unsigned int i=0;i<vt[u].size();i++){
		int v=vt[u][i];
		if(!vis[v])dfs(v);
		siz[u]+=siz[v]; 
	}
}
//结束了。。。
//也许AK了吧，百感交织，感谢自己2年的付出
//算了不半场开香槟了，重点是下午的S组 
//666这个FC还对空格敏感，吓我一跳还以为错了 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i; 
	}
	for(int i=1;i<=n;i++){
		vt[lst[a[i]]+1].push_back(i);
		to[i]=lst[a[i]]+1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++)ans[a[i]]+=siz[i];
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
	return 0;
}
