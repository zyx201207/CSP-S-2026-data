#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
long long m,sm;
long long a[500001];
long long b[500001];
/*
Trick||Treat!
Oct31==Dec25?
Merry Christmas! & Merry Halloween!

从小到大排序，答案一定来自a的一段区间
又，左端点向右走，右端点一定不向左走
双指针|依旧配重

Coconut      5s[loadon]
Super 
这是椰子树上的球，可以在最后一击造成极高伤害。 
生命：2187000
伤害：2187
最终伤害：109350000

Soldier Ant Egg 1s+5s[loadon]
Super
它可以孵化并生成一些有趣的东西……
宠物：x3兵蚁(Ultra) 

Flower       69420s[loadon]
Ultra
它有极长的冷却时间，但它每秒都有10%的概率跳过它的冷却。
生命：忘了
护甲：-729
剧毒伤害：811250/s 

Basic        1s[loadon]
Epic
有史以来最简单的花瓣。
生命：270
伤害：270

宣传zorr
lvl 196,9s:coconut/x2 leaf/x2 iris/missile/wing/soldier ant egg/yuan 

不不不，才****B，我无疑是愤怒的
不不不，才****B，我无疑是愤怒的
不不不，才****B，我无疑是愤怒的
不不不，才****B，我无疑是愤怒的ok. 
透一下吧，那个J组代码全是1536B的也是我，lg uid=1*02**6，
所有的*是一样的，名字有11个字符，4个下划线 
*/
bool check(int l,int r){
	long long exc=1ll*(r-l+1)*a[r];
	long long fac=b[r]-b[l-1];
	if(exc-fac<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int p=0;
	for(int i=1;i<=n;i++){
		while(p<n&&check(i,p+1))p++;
		ans=max(ans,p-i+1);
	}
	cout<<ans;
	return 0;
}
