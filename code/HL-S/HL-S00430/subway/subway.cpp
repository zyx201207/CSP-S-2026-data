#include<bits/stdc++.h>
using namespace std;
long long w[505];
struct op
{
	int a;
	long long t;
}  k[505][505];
int x[505],y[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,biao=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i][1].a;
		if(k[i][1].a!=2)
		{
			biao=1;
		}
		for(int j=1;j<=k[i][1].a;j++)
		{
			cin>>k[i][j+1].a>>k[i][j+1].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(biao==0)
	{
		for(int i=1;i<=q;i++)
		{
			int ans=w[x[i]],di=x[i];
			while(di!=y[i])
			{
				for(int j=1;j<=n;j++)
				{
					if(k[j][2].a==di)
					{
					    di=k[j][3].a;
						ans=ans+k[j][3].t+k[j][2].t;
					}
				}
			}
			ans+=w[y[i]];
			cout<<ans<<endl;
		}
		return 0;
	}
}