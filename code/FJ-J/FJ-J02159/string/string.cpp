#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010]={0},x=0,y=0,z=0,c,d,k;
char b[200010];
string e;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		z=z+a[i];
	}
	c=z/2;
	d=z/2+z%2;
	for(long long i=0;i<c;i++)
	{
		k=i;
		long long j=0,u=n-1; 
		while(k>=a[j])
		{
			k=k-a[j];
			j++;
		}
		k=z-i;
		while(k>=a[j])
		{
			k=k-a[j];
			u--;
		}
		if(b[j]==b[u])
		{
			x++;
		}
	}
	for(long long i=0;i<d;i++)
	{
		k=i;
		long long j=0,u=n-1; 
		while(k>=a[j])
		{
			k=k-a[j];
			j++;
		}
		k=z-i;
		while(k>=a[j])
		{
			k=k-a[j];
			u--;
		}
		if(b[j]==b[u])
		{
			y++;
		}
	}
	cout<<min(x,y);
}
