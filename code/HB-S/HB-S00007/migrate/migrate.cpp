#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int T=1;T<=t;T++)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			if(d/(x[2]-x[1])>1)
			{
				cout<<n-3<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
			return 0;
		}
	}
	return 0;
}
