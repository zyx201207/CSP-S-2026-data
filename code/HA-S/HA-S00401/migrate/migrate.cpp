#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=c;i++)
	{
		int c=0;
		if (t%2==0)
			cout<<"1 2";
		else
			cout<<"0 1";
	}
	return 0;
}
