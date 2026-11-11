#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],nm;
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long i=1,j=n;
	while(i<j)
	{
		if(b[i]==b[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
				i++;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				nm+=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
				nm+=a[i];
				i++;
			}
			else
			{
				nm+=a[i];
				i++;
				j++;
			}			
		}
	}
	cout<<nm;
	return 0;
}
