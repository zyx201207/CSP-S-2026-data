#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int f[501][500002]={0},n,m,d,q,ans=100000,c,s,e,p[502][502],r[1000]={0},t[1000];
	long l[5002];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=n;i++)
	{
		int u;
		cin>>u;
		for(int j=1;j<=u;j++)
		{
			int x,y;
			cin>>y>>x;
			f[i][y]=x;
			r[y]++;
			t[r[y]]=i;
			for(int v=1;v<i;u++)
			{
				if(f[v][y]!=0)
				{
					p[v][i]=x+f[v][y];
					p[i][v]=x+f[v][y];
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(p[i][k]+p[k][j]<p[i][j])
				p[i][j]=p[i][k]+p[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=10000;
		cin>>s>>e;
		for(int i=1;i<=r[s];i++)
		{
			for(int j=1;j<=r[e];j++)
			if(ans>p[t[i]][t[j]]) ans=p[t[i]][t[j]];
		}
		cout<<ans;
	}
	return 0;
}
