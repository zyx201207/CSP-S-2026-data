#include <bits/stdc++.h>
using namespace std;
int am[9999999];
int an[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,p,c=0;
	cin>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>am[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    cin>>an[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		int j=0;
		j+=am[x];
		j+=am[y];
		j+=an[x][y];
		cout<<j<<endl;
	}
	return 0;
}
