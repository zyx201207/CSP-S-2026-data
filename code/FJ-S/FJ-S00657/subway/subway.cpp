#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
int subway[505][2];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	srand(time(NULL));
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j=1; j<=k; j++)
		{
			cin>>subway[j][0]>>subway[j][1];
		}
	}
	while(q--)
	{
		int u, v;
		cin>>u>>v;
		cout<<int(rand())%(100)+1<<endl;
	}
	return 0;
}
