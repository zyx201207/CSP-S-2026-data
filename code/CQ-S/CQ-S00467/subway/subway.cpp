#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int id,tm;
}a[505][1005];
int c,n,m,d,q,w[N],k[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j].id>>a[i][j].tm;
	}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int s=w[x]+w[y];
			while(x!=y)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=k[i];j++)
					{
						if(a[i][j].id==x)
						{
							if(j==2) x=a[i][j-1].id,s+=a[i][j].tm;
							else x=a[i][j+1].id,s+=a[i][j].tm;
						}
					}
				}
			}
			cout<<s<<'\n';
	}
	return 0;
 }

