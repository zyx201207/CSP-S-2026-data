#include<bits/stdc++.h>
using namespace std;

const int M = 5e5 + 10, inf = 2e9;
int c, n, m, d, q;
int w[M] = {};
int dis[500][500];
void floyd()
{
	
	int idx = 11;
	
	for(int i = 1, k; i <= n; i++)
	{
		cin>>k;
		int met[M] = {}, cnt = 0, lstidx = idx;
		for(int j = 1, d; j <= k; j++)
		{
			cin >> met[j] >> d;
			dis[met[j]][idx] = dis[idx][met[j]] = d;
			idx++; 
			cnt++;
		}
		for(int j = lstidx + 1; j < lstidx + cnt; j++)
		{
			dis[j][j-1] = dis[j-1][j] = 0;
		}
	}
	
	for(int i = 1; i <= 500; i++)
		for(int k = 1; k <= 500; k++)
			for(int j = 1; j <= 500; j++)
				dis[i][j]  = dis[j][i] = min(dis[i][j] , dis[i][k] + dis[k][j]);

}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	if(m <= 500)
	{
		memset(dis, 0x3f, sizeof dis);
		for(int i = 1; i <= m; i++)
			cin>>dis[0][i];
		floyd();
		for(int i = 1, s, e; i <= q; i++)
		{
			cin>>s>>e;
			cout<<dis[0][s] + dis[0][e] + dis[s][e]<<endl;
		}
	}//12
	return 0;
}

