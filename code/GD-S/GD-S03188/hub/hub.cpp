#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0ll,f=1ll;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}
/*
还有半小时比赛就结束了
75+0+0+0
不知道能不能进noip
那就当作最后一次游记来写吧
或者说是6年OI生涯回忆录

我从12岁六年级开始接触c++
初中加入学校专门设立的编程班
高中以竞赛生的身份进入市里最好的高中，学费全免
初中班上只有3个人提前批，我是其中之一 
可能与我whk成绩不错有关
然后就到现在

回看这六年
绿名绿勾，只拿过三等奖
OIerDb上是省20000名
我不算出众，甚至算很菜 
我时常问自己：何意味

我常和机房的朋友说：
我六年的青春都浪费在OI上
但如果有再来一次的机会
我还是会在12岁的某一天打开c++

因为旅途本身就是意义

就要这样结束了吗
还真是草率啊

运气好的话，noip再见
到那时我会用一个小时来写的 
*/
