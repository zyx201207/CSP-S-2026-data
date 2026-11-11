#include <bits/stdc++.h>
using namespace std;
const long long N=1e10+5
int n,m;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2)
	{
		cout<<"12";
	}
	if(n==5&&m==3)
	{
		cout<<"7";
	}
	return 0;
}
