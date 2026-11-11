#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){ll x;scanf("%lld",&x);return x;}
const int N=5e5+10,M=300010;
void hyw(){puts("hyw");}
ll n,m,ansy;
ll a[N];
vector<ll>warma[M];
//stack<int>warma[M];
ll ans[M];
//set<int>pans;
vector<ll>pans; 
int x=-1,y=-1,la;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i) warma[i].push_back(0);
	for(int i=1;i<=n;++i) {
	a[i]=read();
	warma[a[i]].push_back(i);
	}
	for(int i=n;i>=1;--i)
	{
		if(pans.empty()) goto worldmachine;
		if(pans[ansy]==i) pans.pop_back();
		worldmachine:
		warma[a[i]].pop_back();
		la=warma[a[i]][warma[a[i]].size()-1];
		pans.push_back(la);
		ansy=pans.size()-1;
		sort(pans.begin(),pans.end());
		
		ans[a[i]]+=(i-pans[ansy]);
	}
	for(int i=1;i<=m;++i) printf("%lld ",ans[i]);
	return 0;
}
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
 
*/
