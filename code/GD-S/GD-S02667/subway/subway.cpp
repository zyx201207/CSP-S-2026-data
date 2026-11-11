#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],t[505][505],a[505][505];
int main()
{
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		int x,y,ans=0;
		cin>>x>>y;
		ans=w[x]+w[y];
		int i=x,j=x;
		while(j<y)
		{
//			cout<<i<<' '<<j<<' '<<t[i][j]<<endl;
			ans+=t[i][j];
			j++;
//			cout<<i<<' '<<j<<' '<<t[i][j]<<endl;
			ans+=t[i][j];
			if(j==y)
				break;
			i++;
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
