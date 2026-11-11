#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int n,m;
long long maxi;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(next_permutation(a,a+n))
	{
		long long x=a[0];
		for(int i=1;i<m;i++)
		{
			x=x&a[i];
		}
		if(x>maxi)
		{
			maxi=x;
		}
	}
	cout<<maxi;
	return 0;
}
