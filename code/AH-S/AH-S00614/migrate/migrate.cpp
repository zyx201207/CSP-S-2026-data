#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		int n;
		long long m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long x=m/(a[2]-a[1]);
		if(n-x-1<0)
			cout<<0<<"\n";
		else
			cout<<n-x-1<<"\n";
	} 
	return 0;
}
