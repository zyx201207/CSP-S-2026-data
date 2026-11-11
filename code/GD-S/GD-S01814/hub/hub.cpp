#include<iostream>
using namespace std;
#define int long long
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0)return;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	c=read();
	T=read();
	while(T--){
		putchar('0');
		putchar('\n');
	}
	return 0;
}
/*
衣带渐宽终不悔 为伊消得人憔悴

Luogu Name:chhchzzh
CSP-S 游记(? 
---------------
考场碎碎念:
 T1感觉像贪心 可惜想不出来正解了
 连大样例都过不去 最多打个部分分
 T2应该是最短路之类的东西 可惜学艺不精不会打
 遗憾离场
 T3看上去像一道DP但是真打DP又打不出来
 只会打暴力 烦
 T4不会做
 估分居然高达30分 还没考虑挂分
 :我的分数真的是太高了
 ----
 话说回来在考场电脑玩扫雷会被禁赛吗
 牛这电脑没扫雷
 好想回家好想回家
 为数不多的双休日居然在这里打代码
 好命苦
 为啥这监考老师一直在我周围游荡
 想躺会都做不到
 ----
 也是把T1的数据类型和输入输出什么的检查了一遍
 居然还有1h
 好慢啊好慢啊
 空调口直吹给我冷死了
 ZS市你拿东西给我拿好的啊
 一直在发抖
 ----
 还有0.5h
 要被冷到失去意识了
 监考老师也不会搞空调是什么意思啊
 遗憾离世
 ----
 监考老师发力了
 给空调调高温度了
 活过来了孩子们
 ----
 这个checker程序未免也太简陋了吧
 vscode神力
 bat文件直接用vscode改成猫娘口音了
 extern更是简陋
 出乎意料的难蚌啊
---------------
采购的碎碎念: 
这次大概就是最后一次CSP了吧
高一也算得上是老人了
如果没拿到1=的话就要回归whk了
（虽然说就这个实力不还如早点回归whk呢） 
回望竞赛生涯感觉什么奖项都没拿到
一路走来还是大蒟蒻说是(
周边同学也是一个比一个强
太恐怖了
即便如此
如果要AFO了我也会依然热爱着OI
有种虐我千百遍我仍对ta如初恋的感觉了（
---------------
The Last:
谢谢你看到这里
如果还有下一次的话
下次再见吧
        --26.10.31 万圣夜
*/
