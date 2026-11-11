#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
int w[N];
int k[540];
int v[N];
int a[505][1050],t[505][1050];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];		
		 }
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
