#include<bits/stdc++.h>
using namespace std;
long long n,l,r,k;
int a[2000005];
char b[2000005],c[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("stding.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]+=a[i-1];
	}
	r=a[n-1]-1;
	for(int i=0;i<n;i++)
	{
		for(int j=a[i-1];j<a[i];j++)
		{
			c[j]=b[i];
		}
	}
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			k++;
		}
		l++;
		r--;
	}
	cout<<k;
	return 0;
}
