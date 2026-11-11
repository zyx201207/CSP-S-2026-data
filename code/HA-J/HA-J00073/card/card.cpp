#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=5e5+5;
void solve();
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	if(ONLINE_JUDGE){
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
	}
	else{
		freopen("card4.in","r",stdin);
	}
	int t=1;
	if(duoce)t=read();
	while(t--)solve();
}
int n,m;
int a[N];
vector<int>dp[N];
int ans[N];
int lst[N];
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=n;i>=1;i--){
		if(lst[a[i]]){
			for(int x:dp[lst[a[i]]])ans[x]++;
		}
		else{
			lst[a[i]]=i;
			for(int x:dp[lst[a[i+1]]])dp[i].emplace_back(x),ans[x]++; 
			dp[i].emplace_back(a[i]);ans[a[i]]++;
		}
//		cout<<endl;
	}

	for(int i=1;i<=m;i++)write(ans[i]),putchar(' ');
}
/*
这不是接竹竿么
对于每一局游戏，拍没有被收走，首先要打出这张拍，
并且这张牌不在任意两张相同的牌中间
1 1 4 5 1 4
当i=1时，有两个间隔，
em
我发现：对于一个游戏，我们知道这是一个桶（？）
或者说，如果说两张相同的牌可以合成，那么
可以看做线段
而要求就是：
如果每遇到一个左端点，那么我们就把他加入栈
然后遇到一个右端点就直接收走所有的其他左端点
求最后还在栈内的左端点数
例如：3121323121
3-in,1-in,2-in,2-out,1-out,3-out,2-in,3-in,1-in,1-out,3-out,2-out,1-in
结果只有1 
如果删除一个左边的点，那么：
首先所有的该点相同的其他点都会改变左右
然后没了
如：121323121
1-in,2-in,2-out,1-out,3-in,2-in,2-out,3-out,1-in,2-in,2-out,1-out
也就是可以看做是：将dp[i]转移到最靠前的一个3的位至j，dp[j+1]。
是不是可以从后往前DP？
和一位
DP滚木么？
如果说，设一个i局之后留下来了的是若干
那么其他的j转移到i之后显然留下来的也是相同的
12345678
112345678=2345678
1112345678=12345678
那怎么办？
记录的是：这个状态为结果的有多少个？
每个DP最多对应一个状态
如果说状态很多怎么办？
比方说3e5个状态
每一个都对应着3e5个数
那么DP是不对的
他让求的是每个颜色出现的总次数
而我们只能O(n)求出所有游戏的最后牌局
哦不对
我看错了
他不是接竹竿
他每一次都是把这个牌再放上去
*/

