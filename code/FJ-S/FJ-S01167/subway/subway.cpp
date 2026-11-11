#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],x[100005],y[100005],u[505][505],v[505][505],k[505];
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
			cin>>u[i][j]>>v[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long sum=1e18,cnt=0;
		cin>>x[i]>>y[i];
		long long nxt=x[i];
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=k[i];l++)
			{
				if(u[j][l]==nxt)
				{
					cnt+=v[j][l];
					if(l!=k[i])
					{
						nxt=u[j][l+1];
						if(nxt==y[i])sum=min(sum,cnt);break;
					}
				}
			}
			if(nxt==y[i])break;
		}
		cout<<sum;
	}
	return 0;
}