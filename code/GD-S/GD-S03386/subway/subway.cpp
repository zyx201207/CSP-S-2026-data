#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],k[5005],a[5005][5005],t[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=n;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+t[1][x]+w[y]+t[1][y];
	}
 } 
