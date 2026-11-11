#include <iostream> 
#define int long long
#define N 500003 
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 3) + (xxxx << 1) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
} 
int n, m, a[N], f[N], cnt[N], lst[N], nxt[N];
bool vis[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i){
		a[i] = read(), lst[a[i]] = i, cnt[i] = 1;
	}
	for(int i = 1; i <= n; ++i) nxt[i] = (lst[a[i]] == i ? 0 : lst[a[i]]);
	for(int i = 1; i <= n; ++i){
		if(nxt[i]) cnt[nxt[i]] += cnt[i], cnt[i] = 0;
		else f[a[i]] += cnt[i], cnt[i + 1] += cnt[i], cnt[i] = 0;
	}
	for(int i = 1; i <= m; ++i) printf("%lld ", f[i]);
	return 0;	
}
/*
对于任意两个有交集的区间 ，不难发现左端点靠前的才会被留下 
CSP-J油鸡：（还有任何不AK的风险存在吗）
8：50 -》 （刚写完T1的窝）bruh欺负残疾人呢。这怎么打的完，没有任何AK的风险了（想到了自己最后十秒钟想到T4但是敲不了的画面）
9：30 -》 （刚写完T2的倭）bruh欺负不熟悉键盘呢。看错题目浪费我心情，边界没处理也浪费我心情，这个时间更浪费我心情呀（ccf fkym）
10：00 -》 （刚写完所有题的我）通透了。。。。（只有T3思路想偏了，T4想实现想得比较久 no more）
-> To be continued... 

upt 2026.10.31 10:53 将T3做法改成了bitset的简单直观清晰不绕弯子直白一目了然吸引程序注意力的方式 
*/
