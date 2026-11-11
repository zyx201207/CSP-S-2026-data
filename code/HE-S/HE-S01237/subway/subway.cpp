#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

int c,n,m,d,q;//测试点编号，线路数，站数，最多经过线路数，出行计划数 
int k;
int w[N];
int both;
int sum;
int ans = 2147483647;

struct Node
{
	int a;
	int t;
}way[505][50005];

void cal(int both,int x,int y)
{
	for(int i = 1;i <= n;i++)//线路 
	{
		sum = 0;
		for(int j = x;j <= both;j++)//站点 
		{
			sum += way[i][j].t;
		}
		for(int l = both;l <= y;l++)
		{
			sum += way[i + 1][l].t;
		}
		sum += w[x] + w[y];
		ans = min(ans,sum);
	}
	cout << ans << endl;
}

void Solve(int x,int y)
{
	for(int i = 1;i <= n;i++)
	{
		both = 0;
		for(int j = 1;j <= k;j++)
		{
			for(int l = 1;l <= k;l++)
			{
				if(way[i][j].a == way[i + 1][l].a) 
				{
					both = way[i][j].a;
					cal(l,x,y);
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	//输入 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) 
	{
		cin >> w[i];	
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++) 
		{
			cin >> way[i][j].a >> way[i][j].t;
		}
	}
	for(int r = 1;r <= q;r++) 
	{
		int x,y;
		cin >> x >> y;
		Solve(x,y);
	}
	
	return 0;
}

