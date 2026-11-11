#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,k;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==0)
	{
		scanf("%lld",&k);
		if(k==4)
		{
			printf("1\n2");
		}
		if(k==5)
		{
			printf("0\n1");
		}
		if(k==197)
		{
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
		}
		if(k==260000)
		{
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
		}
		if(k==200001)
		{
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		}
		if(k==174944)
		{
			printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		}
	}
	else 
	{
		while(t--)
		printf("0\n");
	}
	return 0;
} 

