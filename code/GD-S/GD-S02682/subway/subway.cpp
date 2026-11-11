#include <bits/stdc++.h>
#define s string
#define t long long
#define d double
#define c char
#define For(a,b) for (t a=1;a<=b;a++)
#define _For(a,b) for (t a=0;a<b;a++)
#define W(a) while(a)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
void fo()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
bool st(t st_x,t st_y)
{
	return st_x>st_y;
}

int C,n,m,p,q,w[500010],a[510][20010],b[510][20010],k[510],mn[500010];
/*C:题号 n:线路数 m:站点数 p:站点线路上限 q:问题数 w:地铁口到站厅用时
a:i号线到j号站 b:对应站台到站台用时 k:i号线连通站点数 mn:x地铁口到i站厅最短用时 
*/ 
//a和b拉满会炸内存…… 

struct tt
{
	t way,num;
	/*way:几号线 
	num:在way号线排第几个
	话说这地铁线是单向的还是双向的? 
	*/ 
};
vector<tt>sub[500010];//每个站点通往哪些线路 
struct ss
{
	t spot,tm;
	/*spot:
	    spot<0:|spot|号地铁口
		0<spot<=m:spot号站厅
		m<spot:spot号站点的站台
	
	tm:用时 
	*/
};
queue<ss>wjq; //广搜用的队列 

int main()
{
	fo();
	cin >> C >> n >> m >> p >> q;//读入 
	For(i,m)cin >> w[i]; 
	
	For(i,n)//每个站点连通的线路 
	{
		cin >> k[i];
		For(j,k[i])
		{
			cin >> a[i][j] >> b[i][j];
			sub[a[i][j]].push_back({i,k[i]});
		}
	}
	
	For(i,q)
	{
		t x,y;
		cin >> x >> y;//读取 
		wjq.push({-x,0});//开始 
		bool first=true;//判断是否第一次到达一号站厅 
		mem(mn,m);//初始化......大概 
		W(wjq.size())
		{
			ss www=wjq.front();//获取状态 
			wjq.pop();
			if (www.spot<0)//从地铁口进入站厅 
			{
				wjq.push({abs(www.spot),www.tm+w[abs(www.spot)]});
				continue;
			}
			if (www.spot<=m)//更新至站厅最短时间 并从站厅进入站台 
			{
				if ((mn[www.spot]==0 and (www.spot!=x or first)) or mn[www.spot]>www.tm)
				{
					if (www.spot==x)first=false;
					mn[www.spot]=www.tm;
					wjq.push({www.spot+m,www.tm});
				}
			}
			if (www.spot>m)//从站台乘坐地铁 并结算从站厅至站台的时间 
			{
				t vs=sub[www.spot].size();
				_For(i,vs)
				{
					for (t j=sub[www.spot][i].num+1;j<=k[sub[www.spot][i].way];j++)
					{
						t stn=a[sub[www.spot][i].way][j];//应该是当前站点吧 
						if (mn[stn]>www.tm+b[stn][j] or (mn[stn]==0 and stn!=x))
						{
							wjq.push({stn+m,www.tm+b[sub[www.spot][i].way][www.spot]});
						}
					}
				}
			}
		}
		cout << mn[y]+w[y] << "\n";//就这样吧 写不下去了 
	}
	return 0;
}
//Failed to execute  Error 0: ??????????????
//这什么问题 什么叫此应用无法在你的电脑上运行 
