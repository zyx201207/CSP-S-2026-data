#include<iostream>
#include<cstdio>

using namespace std;

const int M=5e5+5;

int c,n,m,d,q,x,y,e,ans,w[M],k[505],a[505][M],t[505][M];
bool f;

void dfs(int step,int r,int sum)
{
	if(step>=n)
	{
		return;
	}
	if(r==y)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		f=0;
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==r)
			{
				f=1;
				e=j;
				break;
			}
		}
		if(f)
		{
			dfs(step+1,a[i][e+1],sum);
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				for(int p=1;p<=k[j];p++)
				{
					if(a[j][p]==r)
					{
						dfs(step+1,a[j][p],sum+t[j][p]);
					}
				}
			}
		}
	}
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
	while(q--)
	{
		ans=0;
		cin>>x>>y;
		dfs(0,x,0);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
