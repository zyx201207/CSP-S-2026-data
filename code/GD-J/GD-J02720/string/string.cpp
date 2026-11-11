#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	unsigned long long ans=0;
	int i=0,j=n;
	while(i<j)
	{
		if(b[i]!=b[j])
		{
			if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else
			{
				ans+=a[i];
				i++;
				j--;
			}
		}
		else
		{
			if(a[i]<a[j])
			{
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
