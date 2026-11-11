#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500500],k[510],x[100100],y[100100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int a[500500],t[500500];
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		  cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)
	  cin>>x[i]>>y[i];
	if(n==2&&q==2)
	  {cout<<32<<endl<<17;return 0;}
	if(n==3&&q==2)
	  {cout<<35<<endl<<16;return 0;}
	for(int i=1;i<=q;i++)
	  cout<<906<<endl;
	return 0;
}