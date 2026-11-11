#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,time_entrance[1145],time_sub[510][1145];
bool subway[510][1145];
long long G[510][510];
long long dij[510][510];
long long start_station,end_station;

long long get_floyed()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (G[i][k]!=1e18)
				dij[k][j]=dij[j][k]=min(dij[j][k],dij[j][i]+G[i][k]);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
	{
		cin >> time_entrance[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i!=j)
			G[i][j]=dij[i][j]=1e18;
		}
	}
	for (int i=1;i<=n;i++)
	{
		long long station,pass1,time_s1;
		cin >> station;
		for (int j=1;j<=station;j++)
		{
			cin >> pass1 >> time_s1;
			//mapp[i].push_back(edge{pass1});
			time_sub[i][pass1]=time_s1;
			subway[i][pass1]=1;
			for (int k=1;k<i;k++)
			{
				if (subway[k][pass1]==1)//transfer station is found!
				{
					G[i][k]=G[k][i]=min(G[k][i],min(G[i][k],time_sub[i][pass1]+time_sub[k][pass1]));
				}
			}
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cout << subway[i][j] << ' ';
		}
		cout << endl;
	}*/
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << G[i][j] << ' ';
		}
		cout << endl;
	}*/
	get_floyed();
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << dij[i][j] << ' ';
		}
		cout << endl;
	}*/
	for (int i=1;i<=q;i++)
	{
		cin >> start_station >> end_station;
		long long min_ans=1e18;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (subway[j][start_station]==1&&subway[k][end_station]==1)
				{
					min_ans=min(dij[j][k]+time_sub[j][start_station]+time_sub[k][end_station],min_ans);
				}
			}
		}
		min_ans+=time_entrance[start_station];
		min_ans+=time_entrance[end_station];
		printf("%d\n",min_ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
