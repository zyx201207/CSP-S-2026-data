#include<bits/stdc++.h>
using namespace std;
int ans,x,y,c,n,m,d,q,w[500050],a[550][5000],t[550][5000],k;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		cin>>x>>y;
		ans=w[x]+w[y];
		cout<<ans;
	}
	return 0;
 } 
