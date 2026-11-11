#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],s,sum;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
    	s+=a[i];
	}
	if(s%2==0)
	{
		for(int i=n,j=1;i>=j,j<=i;i--,j++)
		{
			if(a[i]!=a[j])
			{
				if(a[i]>a[j])
				{
					sum+=a[i]-a[j];
				}
				else
				{
				    sum+=a[j]-a[i];
                }
				if(c[i]==c[j])
				sum+=abs(a[i]-a[j]);
				else
				sum+=min(a[i],a[j]);
			} 
			else
			{
				if(c[i]!=c[j])
				sum+=a[i];
			}
		}
	}
	else
	{
		long long m=0;
		for(int i=1;i<=n;i++)
		{
			m+=a[i];
			if(m>=(s/2+1))
			{
			    a[i]--;
			    break;
		    }
		}
		for(int i=n,j=1;i>=j,j<=i;i--,j++)
		{
			if(a[i]!=a[j])
			{
				if(a[i]>a[j])
				{
					sum+=a[i]-a[j];
				}
				else
				{
				    sum+=a[j]-a[i];
                }
				if(c[i]==c[j])
				sum+=abs(a[i]-a[j]);
				else
				sum+=min(a[i],a[j]);
			} 
			else
			{
				if(c[i]!=c[j])
				sum+=a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}

