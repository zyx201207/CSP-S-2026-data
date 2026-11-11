#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c[n+5];long long a[n+5];long long sum[n+5];long long x=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=a[i];
	}
	int i=0,j=n-1;
	while(i<j)
	{
		if(sum[i]>sum[j])
		{
			j--;
			if(c[i]!=c[j+1])
			{
				x=x+sum[j+1];
			}
			sum[i]=sum[i]-sum[j+1];
		}
		else
		{
			i++;
			if(c[i-1]!=c[j])
			{
				x=x+sum[i-1];
			}
			sum[j]=sum[j]-sum[i-1];
		}
	}
	cout<<x;
		
	return 0;
}
