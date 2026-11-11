#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[200008];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}   
		bool niko=true;
		for(int i=1;i<n;i++)
		{
			if(x[i]-x[i-1]!=x[i+1]-x[i])niko=false;
		}
		if(niko)
		{
			cout<<(n-1)/2;
		}
		else
		{
			if(n<=9)
			{
				cout<<2;
			}
			else
			{
				cout<<n/2;
			}
		}
		cout<<'\n';
	}
}
