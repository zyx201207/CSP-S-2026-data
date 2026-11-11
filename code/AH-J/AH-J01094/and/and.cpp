#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010],c;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m, n;
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(m==2)
		b[i]=a[i]>>+a[i+1];
		if(m==3)
		b[i]=a[i]>>+a[i+1]>>+a[i+2];
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]<b[i+1])
		{
			c=b[i];
			b[i]=b[i+1];
			b[i+1]=b[i];		
		}
	}
	cout<<b[0];
	return 0;
}
