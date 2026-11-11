#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
long long c,n,m,d,q;
long long w[N],a[N][N],t[N][N],k[N];
bool f[N][3];
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
		int x,y;
		memset(f,0,sizeof(f));
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x)
				{
					f[i][1]=1;
				}
				else if(a[i][j]==y)
				{
					f[i][2]=1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

