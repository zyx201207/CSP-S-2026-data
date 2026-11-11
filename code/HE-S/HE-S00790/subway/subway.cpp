#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int x2,y2;
int x,y;
int w[1000010];
int a[1000010];
int o;
int l;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=q+m+2;i++)
	{
		cin>>a[i];
	}
	cin>>x>>y;
	cin>>x2>>y2;
	for(int i=1;i<=2;i++)
	{
		l=min(w[i],a[i]);
		if(w[i]==a[i])
		{
			l++;
		}
		o=w[i]+a[i]+l;
		cout<<o;
	}
	
	return 0;
 } 
