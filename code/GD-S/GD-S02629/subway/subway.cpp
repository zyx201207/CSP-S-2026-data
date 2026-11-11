#include <bits/stdc++.h>
using namespace std;
int c,now,n,m,d,q,x,y;
int k[1005],a[1005][105],t[1005][105],deep[1005][1005],w[100005];
int ans;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q; 
	for (int i=1;i<=m;i++) 
	{
		cin >>w[i];//从每个地铁口走到展厅要的时间 
	}
	for (int i=1;i<=n;i++)//每个线路相关 
	{
		cin >>k[i];       //经过多少个地铁站
		for (int j=1;j<=k[i];j++)
		{
			cin >>now;
			a[i][now]=1;//第i条线路的地铁站 ,存在为1 ,方便找 

			cin >>t[i][now];//站厅到站台 
		 } 
	}//初始化一下那个啥最近距离 ,每条线路互相 ，暴力一下，哈哈。 
	for (int i=1;i<=n+5;i++)
	{
		for (int j=1;j<=n+5;j++)
		{
			if (i==j)continue;
			deep[i][j]=1e9;
		}
	 } 
	for (int i=1;i<n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int r=1;r<=m;r++)
			{
				if (a[i][r]==1 && a[j][r]==1)//找连通两个线的地铁站 
				{
					deep[i][j]=min(t[i][r]+t[j][r],deep[i][j]);//只是中转部分 
					deep[j][i]=deep[i][j];
					break;
					
				}
			}
		}
	}
	

	for (int i=1;i<=q;i++)
	{
		cin >>x>>y;//起点和终点
		//找起点线路和终点线路
		
		bool yes=0 ;
		int minx=1e9,miny=1e9,nowx,nowy;
		ans=1e9;
		for (int i=1;i<=n;i++)//找对应线路和对应到站台站台的时间 
		{
			if (a[i][x]==a[i][y])//找起点终点到站厅时间min 如果同线 
			{
				ans=w[x]+w[y]+t[i][x]+t[i][y];
				yes=1;
				break;
			}
		 } 
		if (yes)
		{
		 	cout <<ans<<endl;
		 	continue;
		}
		
		bool xx=0,yy=0;
		for (int i=1;i<=n;i++)//耶暴力 第几条线/ 
		{
			for (int j=1;j<=n;j++)
			{
				if (a[i][x]==1)
				{
					
					if (t[i][x]<=minx)
					{
						minx=t[i][x];
						nowx=i;
					}
					xx=1;
				}
				
				
				if (a[j][y]==1)
				{
					
					if (t[j][y]<=miny)
					{
						nowy=j;
						miny=t[j][y];
					}
					yy=1;
				}
				if (xx&&yy)
				{
					ans=min(ans,deep[nowx][nowy]+w[x]+w[y]+minx+miny);

				}
			}
		}
		//换站加上起点终点到地铁口到站台 
		cout <<ans<<endl;
		 
	 } 
	return 0;
}


