#include <bits/stdc++.h>
using namespace std;
int i,j,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>i>>j>>d;
	if(i*j<=d)
	{
		cout<<i++;
	}
	if(i*j>=d)
	{
		cout<<j++;
	}
	
}
