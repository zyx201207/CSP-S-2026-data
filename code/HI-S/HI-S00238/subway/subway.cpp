#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, N_1 = 500 + 5, D = 20 + 5;
struct node
{
	int pt = 0;
	long long dis = 0;
}way[N_1][D];
struct node2
{
	long long dis1;
	long long dis2;
	long long dis;
}fyd[N][N];
long long zt[N], waysz[N_1];
int c, n, m, d ,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			fyd[i][j].dis = fyd[i][j].dis1 = fyd[i][j].dis2 = 1000000000000000000;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> zt[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> waysz[i];
		for(int j = 1; j <= waysz[i]; j++)
		{
			cin>>way[i][j].pt>>way[i][j].dis;
		}
		for(int j = 1; j <= waysz[i]; j++)
		{
			node nowpt1 = way[i][j];
			for(int k = 1; k < j; k++)
			{
				node nowpt2 = way[i][k];
				fyd[nowpt1.pt][nowpt2.pt].dis1 = min(fyd[nowpt1.pt][nowpt2.pt].dis1, nowpt1.dis);
				fyd[nowpt1.pt][nowpt2.pt].dis2 = min(fyd[nowpt1.pt][nowpt2.pt].dis2, nowpt2.dis);
				fyd[nowpt2.pt][nowpt1.pt].dis1 = min(fyd[nowpt2.pt][nowpt1.pt].dis1, nowpt2.dis);
				fyd[nowpt2.pt][nowpt1.pt].dis2 = min(fyd[nowpt2.pt][nowpt1.pt].dis2, nowpt1.dis);  
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			fyd[i][j].dis = fyd[i][j].dis1 + fyd[i][j].dis2;
//			cout<<fyd[i][j].dis<<' ';
		}
//		cout << endl;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			for(int k = 1; k <= m; k++)
			{
				fyd[i][j].dis = min(fyd[i][j].dis, fyd[i][k].dis + fyd[k][j].dis);
				fyd[j][i].dis = min(fyd[j][i].dis, fyd[j][k].dis + fyd[k][i].dis);
			}
		}
  }
  while(q--)
  {
  	int a,b;
		cin >> a >> b;
		cout<<fyd[a][b].dis + zt[a] + zt[b]<<endl; 
	}
//  for(int i = 1; i <= m; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		{
//			cout<<fyd[i][j].dis<<' ';
//		}
//		cout << endl;
//	}
return 0;
}
