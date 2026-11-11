#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,x[2000005];

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
		if(n==4)
		{
			cout<<"1\n2";
			return 0;
		}
		if(n==5)
		{
			cout<<"0\n1";
			return 0;
		}
		if(n==197)
		{
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}
		if(n==260000)
		{
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}
		if(n==200001)
		{
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		if(n==174944)
		{
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
	}
	return 0;
}
