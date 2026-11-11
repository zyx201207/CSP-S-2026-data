#include<bits/stdc++.h>
using namespace std;
long long v[500100],w[500100],x[500100],y[500100],k[500100],t[500100],s[500100],flag[500100],shu[500100];
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long suma=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
		suma+=v[i];
	}
	long long T;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			cin>>t[j]>>s[j];
			suma+=s[j];
			T=s[j];
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c>=7&&c<=11)
	{
		for(long long i=1;i<=q;i++)
		{
			cout<<suma<<'\n';
		}
	}
	else if(c>=12&&c<=19)
	{
		for(long long i=1;i<=q;i++)
		{
			for(int j=x[i];j<=y[i];j++)
			{
				long long sum=0;
				for(int u=1;u<=n;u++)
				{
					for(long long o=1;o<=k[i];o++)
					{
						if(t[o]>=x[i]&&t[o]<=y[i]&&flag[t[o]]==0)
						{
							flag[t[o]]=1;
							sum++;
						}
					}
				}
				long long sumc=0;
				for(int u=1;u<=n;u++)
				{
					for(long long o=1;o<=k[i];o++)
					{
						if(flag[t[o]]==1)
						{
							sumc+=v[t[o]];
						}
					}
				}
				cout<<T*(sum-1)+sumc<<'\n';
				sumc=0,sum=0;
			}
		}
	}
	return 0;
}
