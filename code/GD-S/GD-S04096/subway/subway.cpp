#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],n1[500][500010],x,y,f[500010];
bool n2[500010];
int apple(int s,int e) 
{
	for (int i=1;i<=n;i++)
	{
		if (n1[i][s]!=0)
		{
			for (int j=1;j<=m;j++)
			{
				if (n1[i][j]!=0&&n2[j]!=false&&j!=s)
				{
					if (f[j]==-1)
					{
						f[j]=f[s]+n1[i][s]+n1[i][j];
						n2[s]=false;
					}
					else
					{
						f[j]=min(f[s]+n1[i][s]+n1[i][j],f[j]);
						n2[s]=false;
					}
					if (j==e)
					{
						for (int p=1;p<=m;p++)
						{
							n2[p]=true;
						}
						return 0;
					}
					apple(j,e);
				}
			}
			return 0;
		}
	}
	return 0;
}
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
		int aaa;
		cin>>aaa;
		for (int j=1;j<=aaa;j++)
		{
			int bbb;
			cin>>bbb;
			cin>>n1[i][bbb];
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y;
		for (int j=1;j<=m;j++)
		{
			f[j]=-1;
		}
		f[x]=0;
		for (int p=1;p<=m;p++)
		{
			n2[p]=true;
		}
		apple(x,y);
		cout<<(f[y]+w[x]+w[y])<<endl;
	}
	return 0;
}
