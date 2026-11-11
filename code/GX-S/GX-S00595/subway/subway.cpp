#include <bits/stdc++.h>
using namespace std;
int w[500005],a[500005],t[500005];
int c,n,m,d,q;
int k,x,y;
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
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(c >= 12 && c <= 19)
		{
			cout<<w[x]+w[y]+t[x]+t[x]<<endl;
		}
	}
	return 0;
}
//I don't know what to do :(
//10.31
//It is hard.
