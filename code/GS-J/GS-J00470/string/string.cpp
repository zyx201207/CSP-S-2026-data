#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long ai[n];
	char ci[n];
	long long b=0;
	for(int i=0;i<n;i++) 
	{
		cin>>ai[i]>>ci[i];
		b+=ai[i];
	}
	char bi[b];
	int h=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<ai[i];j++)
		{
			bi[h]=ci[i];
			h++;
		}
	}
	long long count=0;
	for(int l=0;l<b;l++)
	{
		if(bi[l] != bi[b-1-l])
		{
			bi[l] = bi[b-1-l];
			count++;
		}
	}
	cout<<count;
	return 0;
 } 
