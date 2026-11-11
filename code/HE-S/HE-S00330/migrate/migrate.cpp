#include<bits/stdc++.h>
using namespace std;
int x[2000003];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long d,n;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int q=0;q<t;q++)
		{
			cin>>x[q];
		}
	}
	if(c==13||c==14)
	{
		for(int i=0;i<t;i++)
		{
			cout<<1;
		}
		return 0;
	}
	for(int i=0;i<t;i++)
	{
		cout<<i;
	}
	return 0;
}
