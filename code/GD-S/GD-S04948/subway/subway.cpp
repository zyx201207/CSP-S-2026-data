#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,mi[500000],k[500],subway[500][500000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>mi[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x=0,y=0;
			cin>>x>>y;
			subway[i][x]=y;
		}
	}
	
	return 0;
}
