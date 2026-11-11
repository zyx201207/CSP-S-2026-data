#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],ans,dcs[305];
void dfs(int x,int y,int cs)
{
	if (x==y)
	{
		dcs[cs]++;
		return;
	}
	for (int i=x+1; i<=y; i++)
	{
		if (a[x]+d>=a[i])
		{
			dfs(i,y,cs+1);
		}
		else
		{
			return;
		}
	}
	
}
signed main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		memset(dcs,0,sizeof(dcs));
		ans=0;
		cin>>n>>d;
		for (int i=1;i <=n; i++)
		{
			cin>>a[i];
		}
		if (c==11||c==12)
		{
			int dx=a[2]-a[1];
			d/=dx;
			if(d<=1)
			{
				cout<<0<<"\n";
				continue;
			}
			cout<<max((long long)(0),n-2*d+1)<<"\n";
		}
		else
		{
			for (int i=1;i<=n; i++)
			{
				for (int j=i+2;j<=n; j++)
				{
					dfs(i,j,0);
					for (int k=0; k<=305; k++)
					{
						if (dcs[k]==2)
						{
							ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
}
