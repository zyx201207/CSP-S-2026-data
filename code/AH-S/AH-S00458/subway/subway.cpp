#include<bits/stdc++.h>
using namespace std;
int i,j,a,t,c,n,m,d,q,k,x,y,w,s[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w;
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>a>>t;
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<y*10+x<<endl;
	}
	return 0;
}
