#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10005],a[1505][50005],k[50005],s[50005],z[50005],t[1005][50005];
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
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>z[i];
		cout<<t[s[i]][z[i]];
	}
	return 0;
}
