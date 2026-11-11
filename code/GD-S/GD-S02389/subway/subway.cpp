#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	int w[m+5],k[n+5];
	int a[10000005][3],t[10000005][3];
	int ans[1000005]={0};
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<3;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	int r[1000005],y[1000005];
	for(int i=1;i<=n;i++)
	{
		cin>>r[i]>>y[i];
	}
	for(int i=1;1<=q;i++)
	{
		ans[i]+=w[r[i]]+w[y[i]];
		cout<<ans[i]<<endl;
	}
	return 0;

}
