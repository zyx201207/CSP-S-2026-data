#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x=0,y=0,hb=0,he=0,num=0;
long long v[100005],w[500005],k[500],a[500][100005],t[500][500],b[100005],e[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>b[i]>>e[i];
	}
	for (int i=1;i<=q;i++)
	{
		for (int j=1;j<=n;j++)
	{
		for (int h=1;h<=k[j];h++)
		{
			if (a[j][h]==b[i])
			{
				x=j;
				break;
			}
			
		}
	}
	    for (int j=1;j<=n;j++)
	{
		for (int h=1;h<=k[j];h++)
		{
			if (a[j][h]==e[i])
			{
				y=j;
				break;
			}
			
		}
	}
	for (int j=1;j<=k[y];j++){
		num=0;
		hb=0;
		he=0;
		for (int h=1;h<=k[x];h++)
		{
			if (a[x][h]==a[y][j])
			{
				hb=t[x][h];
				he=t[y][j];
				num+=hb+he;
			}
		}}
		num+=w[b[i]]+w[e[i]];
		cout<<num<<endl;
	}
	return 0;
}
