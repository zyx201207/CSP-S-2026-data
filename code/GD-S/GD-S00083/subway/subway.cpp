#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[60],k[60],a[60][60],t[60][60],tu[60][60];
int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tu,32,sizeof(tu));
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
		{
			cin>>a[i][j]>>t[i][j];
		 } 
	}
	for(int i=1; i<=n; i++)
	{
		tu[a[i][1]][a[i][2]]=t[i][1];
		tu[a[i][2]][a[i][1]]=t[i][2];
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++)
		{
			for(int l=1; l<=m; l++)
			{
				tu[i][j]=min(tu[i][j],tu[i][l]+tu[l][j]);
			}
		}
	}
	for(int i=1; i<=q; i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+t[1][x]+tu[x][y]+t[1][y]+w[y]<<endl;
	}
	return 0;
}

