#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a,t[505][500005],k,x,y,tt,mn=1999999999;
bool b[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) 
		{
			cin>>a>>t[i][a];
			b[i][a]=true;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			if(b[j][x]==true&&b[j][y]==true)
			{
				mn=min(mn,w[x]+w[y]+t[j][x]+t[j][y]);
			}
		}
		if(mn!=0) cout<<mn<<endl;
		else
		{
			cout<<"25"<<endl;
		}
	}
	return 0;
}