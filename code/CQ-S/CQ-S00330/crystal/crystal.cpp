#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,lst,ans;
long long m,a[MAXN],pre[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	lst=0;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-lst)-(pre[i]-pre[lst])>m){
			lst++;
		}
		ans=max(ans,i-lst);
	}
	cout<<ans;
	return 0;
}
/*
binomial 894358

14:14 

预测一波数数，大模拟，图论，DP

求求你让我打 WC 吧我什么都会做的/bx/bx/bx

考前自查： 

直面恐惧，斩断循环，拥抱过去，创造未来。 

正于此地，愿你找到想要的书。

Limbus↑company ↑↑↑

生有涯，艺无涯。

再次向突破口冲锋！

——真的有人下午CSP上午写三题吗？

——有的有的。

那我一个喷气空中腰射给你们三个全部爆头了气不气。

神童 加强方案

监管者无法守椅。 

你的意思是，老版电台回归了？

空投补给，已就绪。

…… 

空中炮艇，已就绪。 

让世界，彻底遗忘我。

*寒风呼啸，站在你面前的，是一位真正的英雄。 

全世界音游最区之人，rks高达 12.53！！！

毒性子弹高打低，_________________


14:28

开考

14:33

T1过大样例。

14:39

T2有点思路？

14:41

感觉没问题，开写

15:07

T2 过大样例

15:13

T3 n^3

15:18

T3 疑似n^2

15:25

证明疑似n^2（？

感觉可以进化到均摊O(n)

先写下

15:29

好像进化不了……

15:45

好像前半部分不是N^2是N???

不管先写

16:19

n^2 过了，写特殊性质去了

16:28

特A

16:35

会特B 

17:00

疑似特B过？？？

感觉特C可能有难度，去做D了 
 
 17:09
 
 k=2 会了
 
 17:11
 
 莫非可以推广？别告诉我就这么过了 
*/

