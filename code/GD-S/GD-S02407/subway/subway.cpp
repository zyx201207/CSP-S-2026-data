#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll c,n,m,d,q;
lll dis[5200][5200],t[5200][5200];
lll sub[5200];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	if(c>=30)
	{
		for(int i=1;i<=m;i++) cin>>sub[i];
		for(int i=1;i<=n;i++)
	{
		lll k;cin>>k;
		lll t1[5200]={0},a1[5200]={0};
		for(int j=1;j<=k;j++)
		{
			cin>>a1[j]>>t1[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int j1=j+1;j1<=k;j1++)
			{
				if(t[a1[j]][a1[j1]]>t1[j]+t1[j1])
				t[a1[j]][a1[j1]]=t[a1[j1]][a1[j]]=t1[j]+t1[j1];
			}
		}
	}
		
	}
	else {
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
	t[i][j]=1e9;
	dis[i][j]=1e9;
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<dis[i][j]<<"          ";
		cout<<endl;
	}*/
	for(int i=1;i<=m;i++) cin>>sub[i];
	for(int i=1;i<=n;i++)
	{
		lll k;cin>>k;
		lll t1[5200]={0},a1[5200]={0};
		for(int j=1;j<=k;j++)
		{
			cin>>a1[j]>>t1[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int j1=j+1;j1<=k;j1++)
			{
				if(t[a1[j]][a1[j1]]>t1[j]+t1[j1])
				t[a1[j]][a1[j1]]=t[a1[j1]][a1[j]]=t1[j]+t1[j1];
			}
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	dis[i][j]=t[i][j];
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<dis[i][j]<<"          ";
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++)
	{
		lll x,y;cin>>x>>y;
		cout<<dis[x][y]+sub[x]+sub[y]<<endl;
	}}
	fclose(stdin);fclose(stdout);
	return 0;
 } 
