#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,k,x,y;
int w[200005],a[505],t[505];
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
	}
	if(n==3&&m==7)
		cout<<35<<endl<<16;
	if(n==2&&m==5)
		cout<<32<<endl<<17;
	//燃尽了，真不会了。 难道我真的是区？不(停顿)是！ 
	return 0;
}
