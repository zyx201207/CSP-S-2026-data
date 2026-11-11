#include<bits/stdc++.h>
using namespace std;
#define int long long
#define minni minn[i]
int w[500005];
struct node {
	int guo,time;
} a[505][505];
vector<node>road[505];
struct node2 {
	int arrive,step,last;
};
int chang[505],minn[2005][2005];
int c,n,m,d,q,x,y;
bool operator<(node2 xx,node2 yy) {
	return xx.step>yy.step;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++)cin>>w[i];
	for (int i=1; i<=n; i++) {
		cin>>chang[i];
		for (int j=1; j<=chang[i]; j++) {
			cin>>a[i][j].guo>>a[i][j].time;
			road[a[i][j].guo].push_back({i,a[i][j].time});
		}
	}
//	for (int i=1;i<=m;i++)
//		{
//		cout<<i<<' ';
//		for (auto k:road[i])cout<<k.guo<<' '<<k.time<<'\n';
//		cout<<endl<<endl;
//		}
	memset(minn,0x3f3f3f,sizeof(minn));
	for (int i=1; i<=m; i++) {
		priority_queue<node2>qq;
		qq.push({i,0,-1});
		minni[i]=0;
		while (!qq.empty()) 
		{
			node2 x=qq.top();//arrive出发点,step步数时间,last上一次乘坐的线路 
			qq.pop();
//			cout<<x.arrive<<' '<<x.step<<' '<<x.last<<' '<<endl;
//			if (minni[x.arrive]<=x.step)continue;
//
//			if (x.arrive==i)//最开始不用出站台，直接进 
//				{
//				for (auto k:road[x.arrive]) //guo几号线,time是花时间 
//					{
//					for (int j=1;j<=chang[k.guo];j++) //guo是指到达的地方，time是指进出站台的时间 
//						{
//						if (minni[a[k.guo][j].guo]>minni[x.arrive]+a[k.guo][j].time)
//							{
//							minni[a[k.guo][j].guo]=minni[x.arrive]+a[k.guo][j].time;
//							qq.push({a[k.guo][j].guo,minni[x.arrive]+a[k.guo][j].time,k.guo});
//							} 
//							
//						}
//					}
//				continue;
//				}
			for (auto k:road[x.arrive]) //guo几号线,time是花时间 
			{
				if (k.guo!=x.last) 
				{
					for (int j=1;j<=chang[k.guo];j++) 
					{
						if (minni[a[k.guo][j].guo]>minni[x.arrive]+a[k.guo][j].time+k.time)
							{
							minni[a[k.guo][j].guo]=minni[x.arrive]+a[k.guo][j].time+k.time;
							qq.push({a[k.guo][j].guo,minni[x.arrive]+a[k.guo][j].time+k.time,k.guo});
							}
					}
				}
			}
		}
	}
//	for (int i=1; i<=m; i++) {
//		for (int j=1; j<=m; j++)
//			cout<<minni[j]<<' ';
//		cout<<endl;
//	}
	while (q--)
		{
		cin>>x>>y;
		//dfs(x,0,0);
		cout<<minn[x][y]+w[x]+w[y]<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
