#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int i=0;
	int j=n-1;
	long long s=0;
	while(i<j)
	{
		if(c[i]==c[j])
		{
			if(a[i]==a[j])
			{
				i++;
				j--;
				continue;
			}
			else
			{
				if(a[i]>a[j])
				{
					a[i]=a[i]-a[j];
					j--;
					continue;
				}
				else
				{
					a[j]=a[j]-a[i];
					i++;
					continue;
				}
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				s+=a[j];
				a[i]=a[i]-a[j];
				j--;
				continue;
			}
			else
			{
				s+=a[i];
				a[j]=a[j]-a[i];
				i++;
				continue;
			}
		}
	}
	cout<<s;
	return 0;
}
