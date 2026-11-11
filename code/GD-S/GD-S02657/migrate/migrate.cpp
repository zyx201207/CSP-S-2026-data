#include<bits/stdc++.h>
using namespace std;
long long a[114514];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t;
	cin>>c>>t;
	for(long long v=1;v<=t;v++)
	{
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n-(d+1)*d/2>=0)cout<<n-(d+1)*d/2<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
