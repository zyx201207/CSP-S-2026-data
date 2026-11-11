#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;int a[500005],ans=0,k;
int vis[505][1010];

int find(int x,int y)
	{
	int ans=0;
	ans+=a[x];
	for (int j=1;j<=n;j++)
		{int find_x=0,find_y=0;
		for (int i=1;i<=2*k;i+=2)
			{
			if (a[i]==x) find_x=1;
			if (a[i]==y) find_y=1;
			}
		if (find_x && find_y) 
			{
			ans+=vis[2][2]+vis[2][4]+a[y];
			return ans;
			}
		}
	for (int i=1;i<=m;i++) ans+=a[i];
	return ans;
	}
int main ()
	{
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		{
		cin>>k;
		for (int j=1;j<=2*k;j++)
			{
			cin>>vis[i][j];
			}
		}
	while (q--)
		{
		int x,y;
		cin>>x>>y;
		ans=find(x,y);
		cout<<ans<<endl;
		}
	return 0;
	}
