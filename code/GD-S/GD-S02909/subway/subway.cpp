#include <bits/stdc++.h>
using namespace std;
int f[500][500];
int dfs(int i,int j)
{
	for(int q=1;q<abs(i-j);q++)
	{
		if(f[i][i+1]!=0&&f[j][j-1]!=0)
		{
			f[i][j]=f[i][i+1]+f[j-1][j];
		}
	}
	return f[i][j];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[500005];
	int num[500005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}

	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int mete[500005];
		int preid=0;
		for(int j=1;j<=x;j++)
		{
			int id,met;
			cin>>id>>met;
			mete[id]=met;
			if(j==1)
			{
				preid=id;
			}
			else
			{
				f[preid][id]=mete[preid]+mete[id];
			}
		}
	}
	for(int i=1;i<m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(f[i][j]!=0)
			{
				continue;
			}
			else
			{
				f[i][j]=dfs(i,j);
			}
		}
	}
	while(q--)
	{
		int be,en;
		cin>>be>>en;
		cout<<w[be]+f[be][en]+w[en]<<endl;
	}
	return 0;
 } 
