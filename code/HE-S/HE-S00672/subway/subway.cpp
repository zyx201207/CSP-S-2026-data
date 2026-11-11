#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[505][505],t[505][505];
int w[500005];
//int cnt[500005];
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
//			cnt[a[i][j]]++;
		}
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		int minn=1e9+5;
		int sum=0;
		sum=w[x]+w[y];
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x)
				{
					for(int l=1;l<=k[i];l++)
					{
						if(a[i][l]==y)
						{
							f=1;
							for(int u=min(j,l);u<=max(j,l);u++)
							{
								sum+=t[i][u];
							}
							minn=min(minn,sum);
						}
					}
					if(!f)
					{
						for(int e=1;e<=n;e++)
						{
							for(int g=1;g<=k[e];g++)
							{
								if(a[e][g]==y)
								{
									for(int h=1;h<=k[e];h++)
									{
										for(int h1=1;h1<=k[i];h1++)
										{
											if(a[i][h]==a[e][h1])
											{
												for(int co=min(j,h);co<=max(j,h);co++)
												{
													sum+=t[i][co];
												}
												for(int co=min(g,h1);co<=max(g,h1);co++)
												{
													sum+=t[e][co];
												}
												minn=min(minn,sum);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<minn<<endl;
	}
}
