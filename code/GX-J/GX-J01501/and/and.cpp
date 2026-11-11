#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,s;
	cin>>a>>s;
	long long arr[1000011]={0};
	for(int q=0;q<a;q++)
	{
		cin>>arr[q];
	}
	int z=0,x=0;
	for(int q=0;q<a;q++)
	{
		for(int w=0;w<a;w++)
		{
			z=arr[q] and arr[w];
			if(z>x)
			{
				x=z;
			}
		}
	}
	cout<<x;
	return 0;
}
