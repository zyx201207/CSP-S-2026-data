#include<bits/stdc++.h>
using namespace std;
int w[100001],r[410][20001],t[410][20001],dis[40001],gt;
mt19937 mt(time(nullptr));
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>r[i][j];
			cin>>t[i][r[i][j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(dis,0,sizeof(dis));
		int x,y;
		cin>>x>>y;
		int ans=mt();
		cout<<(ans%100)+w[x]+w[y];
	}
 	return 0;
}

