#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){int x;scanf("%lld",&x);return x;}
//const int N=
//void hyw(){puts("hyw");}
string ans="0000";
char a='1',b='0';
bool f1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,X1,y,Y1;
	cin>>x>>X1>>y>>Y1;
	ans[0]=(x==y)?a:b;
	if(ans[0]==b) goto worldmachine;
	f1=('A'<=X1[2]&&X1[2]<='F'&&'A'<=Y1[2]&&Y1[2]<='F')?1:0;
	ans[1]=(X1[0]==Y1[0]&&X1[1]==Y1[1]&&f1)?a:b;
	if(ans[1]==b) goto worldmachine;
	ans[2]=(('A'<=X1[2]&&X1[2]<='C'&&'A'<=Y1[2]&&Y1[2]<='C')||('D'<=X1[2]&&X1[2]<='F'&&'D'<=Y1[2]&&Y1[2]<='F'))?a:b; 
	if(ans[2]==b) goto worldmachine;
	ans[3]=((X1[2]+1==Y1[2]&&Y1[2]!='D')||(X1[2]==Y1[2]+1&&X1[2]!='D'))?a:b; 
	worldmachine:
	cout<<ans;
	return 0;
}
//豪豪代码 
/*
(超考试时间14分钟了试题终于发解压密码) 
玛德琳娜电塔 纯白/warma(翻唱) 
放学后的街坊 早已华灯初放
不愿进入人潮 避开熙熙攘攘
荧幕上的人啊 去向哪个片场
沉浸虚无幻想 跟着音乐清唱

谁得到了奖赏 谁又落入情网 
人人幸福安康 只我黯然神伤
若是感到迷茫 跳支舞又何妨
(我好像不记了)

渐变色的枝丫 生出水母花
糖针形成海洋 人鱼撒着慌
玛德琳娜电塔 全天候喊话 
*/
