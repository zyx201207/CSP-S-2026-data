#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005];
ll t[500005];
vector<int>v;
signed main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			auto it=find(v.begin(),v.end(),a[j]);
			if(it!=v.end()){
				v.erase(it,v.end());
			}
			v.push_back(a[j]);
		}
		for(auto x:v){
			t[x]++;
//			cout<<x<<" ";
		}
//		cout<<"\n";
		v.clear(); 
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	return 0;
} 
//Trick||Treat!
/*
嘿，有缘人，既然你看到这了，那么我告诉你一些大实话吧。
今年可能是我最后一次参加CSP-j/s了，没拿到1=就会被迫退役
如果真的有人看到这里，为我祝福一下吧
希望你能RP++，代码我都是骗分的（除了T1）
~~对了，关注洛谷@Iain_~~ 
刷题九日思家中游戏
2026 洛谷Iain_
强欲摸鱼处，无人送游来。
遥思故家游，应在家中开。
问：本文中的摸鱼代表了作者什么样的情感？
答：表达了作者思念曾经在家中玩游戏的美好时光，以及对同样在刷题的人的同情
WA=Wonderful answer 美好的答案
TLE=time lots empty 时间十分空闲
MLE=miton lots empty 空间十分宽敞
UKE=unkonw empty 不明所以的空闲
UKE=UK error 英国的错误（不是你的）
OLE=out lots empty输出十分充裕
RE=repoter empty记者充裕（出名了） 
再好的know也会栽在now
再好的lover也有over
再好的friend也有end
再好的teacher都会教each
但是，再坏的programming也能in
再差的iostream也有team
如果a=1,b=2,c=3,d=4……z=26,那么什么单词为100呢？
a b c d e f g h i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
是知道吗？know=11+14+15+23=63，不是 
是学习吗？study=19+20+21+4+25=89，不是
是爱情吗？lovely=12+15+22+5+12+25=91,不是
是工作吗？work=23+15+18+11=67，也不是
那么什么是100呢？
答案就在我们的代码中：
iostream=9+15+19+20+18+5+1+13=100
所以，坚持下去吧！ 
冷知识，ccf=��￡ 
对了，
//mian
//freopen(".in","r",stdin); 
//freopen(".out","w",stdout);




















 
~~csp还有-x天，接龙哈~~ 
*/
