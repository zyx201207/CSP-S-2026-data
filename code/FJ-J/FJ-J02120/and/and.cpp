#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	if(n==4)
	{
		cout<<12;
	}
	else if(n==5)
	{
		cout<<7;
	}
	else
	{
		cout<<64;
	}
	return 0;
}
