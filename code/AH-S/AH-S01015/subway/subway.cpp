#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,edge[10010][10010],t1,t[1000000],l[100000],w[101000],fr,en;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	if(c<=11&&c>=7)
	{
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)edge[i][j]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++)
		{
			cin>>t1;
			for(int j=1;j<=t1;j++)cin>>t[j]>>l[j];
			if(t1==2){edge[t[1]][t[2]]=min(edge[t[1]][t[2]],l[1]+l[2]);edge[t[2]][t[1]]=min(edge[t[2]][t[1]],l[1]+l[2]);}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n&&i!=k;i++)
			{
				for(int j=i+1;j<=n&&j!=k;j++)
				{
					edge[i][j]=min(edge[i][k]+edge[k][j],edge[i][j]);
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>fr>>en;
			if(fr==en)cout<<0<<'\n';
			else
			{
				cout<<edge[fr][en]+w[fr]+w[en]<<endl;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)edge[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		cin>>t1;
		for(int j=1;j<=t1;j++)cin>>t[j]>>l[j];
		for(int j=1;j<=t1;j++)
		{
			for(int k=j+1;k<=t1;k++)
			{
				edge[t[j]][t[k]]=min(edge[t[j]][t[k]],l[j]+l[k]);
				edge[t[k]][t[j]]=min(edge[t[k]][t[j]],l[j]+l[k]);
			}
		}
	}
	for(int i=1;i<=n;i++)edge[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
					edge[i][j]=min(edge[i][k]+edge[k][j],edge[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>fr>>en;
		if(fr==en)cout<<0<<'\n';
		else
		{
			cout<<edge[fr][en]+w[fr]+w[en]<<endl;
		}
	}
	return 0;
}
