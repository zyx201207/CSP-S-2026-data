#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int tid,n,m,d,q,f[505][505];//f[i][j] 表示线路 i 到线路 j 的最短换乘时间 
struct node
{
	int w;//地面层到站厅层时间 
	vector<pair<int,int> > line;//first 为线路，second 为到该线路时间 
}a[514514];
signed main()
{
	ioimprove();
	FILE("subway");
	cin>>tid>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>a[i].w;
	for(int i = 1;i <= n;i++)
	{
		int len;cin>>len;
		for(int j = 1,x,y;j <= len;j++) cin>>x>>y,a[x].line.push_back({i,y});
	}
	memset(f,0x3f,sizeof f);
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int i = 1;i <= m;i++)//考虑一次换乘的情况 
		for(int j = 0;j < a[i].line.size();j++)
			for(int k = j + 1;k < a[i].line.size();k++)
				f[a[i].line[j].first][a[i].line[k].first] = min(f[a[i].line[j].first][a[i].line[k].first],a[i].line[j].second + a[i].line[k].second);
	//for(int i = 1;i <= n;i++)
	//	for(int j = 1;j <= n;j++) cerr<<f[i][j]<<"\n"; 
	for(int k = 1;k <= n;k++)//floyd
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while(q--)
	{
		int x,y,ans = 0,minn = 0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		ans += a[x].w + a[y].w;
		for(int i = 0;i < a[x].line.size();i++)
			for(int j = 0;j < a[y].line.size();j++) minn = min(minn,a[x].line[i].second + a[y].line[j].second + f[min(a[x].line[i].first,a[y].line[j].first)][max(a[x].line[i].first,a[y].line[j].first)]);
		cout<<ans + minn<<"\n";
	}
	
	return 0;
}
//吓哭了啥大阅读 
//分层图吗有点意思 
//分层图个鬼分层完空间直接爆炸
//复杂度 O(qd^2)？感觉很对
//线路上所有点等价，考虑线路到线路最短换乘时间
//我去 n \leq 500 是不是 floyd 跑就行
//想不出问题，先开写吧 
//哎东鹏特饮喝多了为啥会困啊有道理吗？？？ 
//第一发有点挂了，看起来没问题是不是溢出了？ 
//。。。不是溢出，floyd 写错了唐不唐 
//还有为啥我这个文件叫未命名 2 而不是 subway 
//好的第二发失败，那么多逆天负数感觉就是溢出啊 
//不能是 0x7f7f7f7f7f7f7f7f * 2 溢出了吧 
//好像还真是，但是还有啥问题，真有点蒙了 
//唐了顺序反了，我已了解问题
//第四发过了，牛逼
//张雪峰老师保佑别跑太慢（？）
//1217king 老师 et magnet 保佑小常数通过 
//能赢吗？

//先让我感慨一下
//秦皇汉武
//略输文采
//唐宗宋祖
//略逊风骚
//一代天骄
//成吉思汗
//只识弯弓射大雕
//俱往矣
//数风流人物
//还看今朝 

// 18:03 更正样例解释浪费我 1min 差评！！！ 
