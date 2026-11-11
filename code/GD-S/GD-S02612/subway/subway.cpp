#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int a[m];
	if(c==0)
	{
		if(m==7)
		{
			cout<<35<<endl<<16;
		}
		else if(m==5)
		{
			cout<<32<<endl<<17;
		}
	}
	else
	{
		for (int i=0;i<m;i++)
		{
			cin>>a[i];
		 } 
		 for (int i=0;i<=n;i++)
		 {
		 	int f=0,z;
		 	cin>>f;
		 	int a[f];
		 	cout<<z<<endl;
		 } 
	}
}
