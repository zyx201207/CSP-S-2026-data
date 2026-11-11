#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	int w[500000],a[500][500000],t[500][500000],k;
	for(int i=0; i<m ;i++)
	{
		cin>>w[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>k;
		for(int j=0; j<k; j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
