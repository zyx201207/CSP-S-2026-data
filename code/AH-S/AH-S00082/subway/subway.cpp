#include <bits/stdc++.h>
using namespace std;
const int maxn=5*10e5+10;
int w[maxn];
int k[510];
int a[510][maxn];//i线经过j地铁站 
int t[510][maxn];//i线站台到j站厅时间 
int x[maxn];
int y[maxn];
int ans[maxn];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; //测试点编号、n地铁线路数、
//m地铁站数、d每个地铁站最多被几条线路经过，q以及出行计划数。
	for(int i =1 ;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int  i = 1 ;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1 ; j <= k[i] ;j++ )
		{
			int b,c;//i经过b站 z站厅到i站台时间 
			cin>>b>>c;
			a[i][b]=1;//i过j站 
			t[b][i]=c;
		}
	
	}
	
	for(int i =1  ;i <= q ; i++)
	{
		cin>>x[i]>>y[i];
	}
	
	for(int i =1  ;i <= q ; i++)
	{
	for(int j =1 ;j <= n ;j++)
	{
		if(a[j][x[i]]==1&&a[j][y[i]]==1)//j线 
	{
		ans[i]=min(ans[i],w[x[i]]+w[y[i]]+t[x[i]][j]+t[y[i]][j]);
	}
	}	
	}
	for(int i =1 ; i <= q ;i++)
	{
		cout<<ans[i];
	}
	return 0;
}

/*
C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Assembler messages:
143		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 0000000261292c67 too large for field of 4 bytes at 0000000000000167
165		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c2524fbb too large for field of 4 bytes at 00000000000001bb
170		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c1212293 too large for field of 4 bytes at 00000000000001d3
192		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c12122e8 too large for field of 4 bytes at 0000000000000228
207		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c252506c too large for field of 4 bytes at 000000000000026c
222		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c1212370 too large for field of 4 bytes at 00000000000002b0
231		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c25250db too large for field of 4 bytes at 00000000000002db
241		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c12123c9 too large for field of 4 bytes at 0000000000000309
249		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 0000000261292e2d too large for field of 4 bytes at 000000000000032d
255		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c2525146 too large for field of 4 bytes at 0000000000000346
263		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 0000000261292e6a too large for field of 4 bytes at 000000000000036a
270		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c3837ec6 too large for field of 4 bytes at 0000000000000386
279		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c3837eec too large for field of 4 bytes at 00000000000003ac
298		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c3837f2c too large for field of 4 bytes at 00000000000003ec
354		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c4b4ac8c too large for field of 4 bytes at 0000000000000424
378		C:\Users\ADMINI~1\AppData\Local\Temp\cciEUvRs.s	Error: value of 00000004c4b4acbc too large for field of 4 bytes at 0000000000000454

*/
