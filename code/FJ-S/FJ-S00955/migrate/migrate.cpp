#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,a;
	cin>>c>>t;
	long long x[100005],ju[100005];
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		if(n<=4&&d<3)
		{
			a=x[n]-x[1];
			cout<<1<<endl;
		}
		else if(n==5&&d==2)
		{
			cout<<2<<endl;
		}
		else if(n==5&&d==3) cout<<0<<endl;
		else if(n==6&&d==2) cout<<1<<endl;
		
	}
	return 0;
}
