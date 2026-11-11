#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	double a[10010];
	int sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
    }
    for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
	    {
	    	if(a[i]>a[j])
	    	{
	    		a[i]=a[j];
	    		m-=a[i]-a[j];
		    }
		    else if(a[i]<a[j])
		    {
		    	a[j]=a[i];
		    	m-=a[j]-a[i];
			}
			if(a[j]==a[i])
			{
				j++;
				i++;
				sum++;
				a[i-1]=a[i];
			}
	    }
	}
	if(sum%3==0) sum=sum/2;
	cout<<sum;
	return 0;
}
