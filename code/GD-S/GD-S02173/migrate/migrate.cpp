#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int op=0;op<t;op++)
	{
		int n,m;
		cin>>n>>m;
		int a[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n%m==1)
		{
			cout<<2<<endl;
		}
		else if(n%m==0)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
