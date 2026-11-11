#include<bits/stdc++.h>
using namespace std;
void in(long long &x){
	int f=1;x=0;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	x*=f;
}
const int N=5e5+5;
long long n,m,a[N],ned=0,cnt=0,ans=0,fir;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	in(n);in(m);
	for(int i=1;i<=n;i++)in(a[i]);
	sort(a+1,a+n+1);
	fir=1,cnt=1;
	for(int i=2;i<=n;i++){
		long long det=a[i]-a[i-1];
		ned+=cnt*det;cnt++;
		while(ned>m){cnt--;ned-=a[i]-a[fir],fir++;}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
//1024=2^10->很好的考号
/*
停不下的 止不住的 这城市的雨啊
荡起的水纹能撼动什么
这双手曾 紧握住的 并非沉重伞柄
也并非如此冰冷啊

雨中妄图振翅的飞鸟
被回忆的枷锁所缠绕
只得呆呆望着泛光的街道 
昨日孩童纯白的裙角
被连绵的阴雨污浊后
便开始憧憬更加刺目繁复色彩了

若愿望注定落空断折
那这涂抹幸福的礼盒
盛装了孤独失落或是什么
永远凝固在青空的泪辙
尝试将荧光集结映射
即使微不足道难以点亮城市的干涸

在某个角落听着雨落的人啊
这般的漫漫长夜过去后
仍会爱着这些漆黑时光吗
成为优秀的大人了吗
那日义无反顾离去后
便被淋漓雨幕全然吞没无法回答

连停下来的话 都苦涩到无法说出
只得在冰冷雨幕中静默回望
看到了让人心酸的 幼时的我兴奋地
迫不及待地打开这
骗人的名为"成长"的礼物

阴雨后苍蓝天空 温度略有所回升 
*/ 

