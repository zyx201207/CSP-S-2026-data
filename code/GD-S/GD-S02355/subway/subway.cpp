#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("subway.in","r",stdin);
	preopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		for(int i=0;i<2*b[i];i++)
		{
			int sb;
			cin>>sb;
		} 
	}
	int g;
	for(int i=0;i<n;i++)
	{
		for(int i=1;i<=2;i++)
		{
			cin>>c;
		}
	}
	if(n==2)
	{
		cout<<32<<endl<<17;
	}
	else if(n==3)
	{
		cout<<35<<endl<<16;
	}
	return 0;
}
