#include<bits/stdc++.h>
using namespace std;
long long a333[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	std::cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		std::cin>>a333[i];
	}

	sort(a333+1,a333+n+1);
	long long fff=0x3fffffff;
	for(int i=n;i>=n-m+1;i--)
	{
		fff=fff & a333[i];
	}
	std::cout<<fff;
	return 0;
}
//oh no!!!!!!!!!!!
/*my A~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
deng deng deng deng~~~~~~~~~~~~~deng deng`dengdeng`~~~~~~~~~~~~~~~~~~~~
^V^
























*/

