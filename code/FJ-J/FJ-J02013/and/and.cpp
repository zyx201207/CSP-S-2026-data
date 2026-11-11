#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			int num;
			num=a[i]&a[j];
			if(num>max)
			{
				max=num;
			}
		}
		if(i==n-1)
		{
			cout<<max;
		}
		
	} 
} 
