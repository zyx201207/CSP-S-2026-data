#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200010],b[200010];
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(long long i=0;i<m;i++)
	{
		int max=0;
		for(long long j=i+1;j<n;j++)
	    {
	    	int s=a[i] and a[j];
		    if(s>max)
		    {
		    	max=a[i] and a[j];
			}
	    }
	    sum=sum and max;
	}
	cout<<sum;
}
