#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505];
int cc(int x,int y)
{
	int ans=w[x]+w[y],book[505],plan=0,plan2=0,p1=0,l=1;
	book[1]=x;
	int d=1;
	for(int i=1;i<=n;i++)
	{
		int time1=0;
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==y)
			{
				ans+=t[i][j];
				return ans;
			}
			else if(a[i][j]==book[d])
			{
				plan=i;
				plan2=j;
				
				l=i;
				if(a[i][j]==x&&p1==0)
				{
					ans+=t[i][j];
					p1=1;
					i=1;
				}
				book[d]=a[i][j+1];
				d++;
			}
			else if(a[i][j]==book[d-1]&&plan!=l)
			{
				time1=t[i][j]+t[plan][plan2];
					l=i;
					i=1;
				book[d]=a[i][j+1];
				d++;
			}
			
		}
		ans+=time1;
	}
	return ans;
}
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
		cout<<cc(x,y)<<endl;
	}
	return 0;
}
