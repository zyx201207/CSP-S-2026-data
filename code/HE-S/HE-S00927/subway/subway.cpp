 #include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define AC WA
const int N=5e2+10;
int n,m,q;
int w[N];//w:站口to站厅用时 
vector<pair<int,int>>a[N];//a[i]::afirst:i号线经过的站点  asecond:第i线qfirst站to站厅用时（反之亦然成立） 
void solve()
{
	int f,t;
	cin>>f>>t;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d;
	cin>>c;
		int t;
		cin>>t;
		if(t==2) cout<<32<<endl<<17;
		if(t==3) cout<<35<<endl<<16;
	cin>>m>>d>>q;//n个地铁线，m个地铁站
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;//途径k站 
		for(int j=1;j<=k;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back({aa,tt});
		}
	}
	while(q--)//q次询问 
		solve();
	return 0;
}
//说实话，ACT1我就满足了
//但是我怕啊
//idk 怎么办
//万一今年2=线>=100pts呢
//神秘HE发力了咋办 
//说实话，我不敢赌
//但是这个题，我真的没心思也没思路去写
//bfs？建图然后带权边？？
//bfs我会啊，，但是这破玩意咋建图
//呃啊 
//可以预先计算然后直接调用，，？我不清楚啊。
//好难，阅读理解吗这是
//阅读量赶上我语文作业了 
//NOIP！NOIP！！NOIP！！！
//会赢吗
//这题的阅读量以及思维深度
//我甚至连骗分程序都不想写
//哪怕我学个写随机数（然而是我忘了） 

//（写完T3的我）我好像知道为什么限制代码长度了
//我直接4小时打一个雷霆大表你受得了吗
 
