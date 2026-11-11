//GZ-J00014 德江县实验中学 张喜灵 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,f=0,e=0,h=0,g;
	cin>>n;
	int a[n];
	char c[n];
	string b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			h=1;
		}
		g=a[i];
	}
	if(h==1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				b[j+f]=c[i];
			}
			f+=a[i];
		}
		for(int i=0;i<f/2;i++)
		{
			if(b[i]!=b[f-1-i])
			{
				e++;
			}
		}
		cout<<e;
	}
	if(h==0)
	{
		for(int i=0;i<n;i++)
		{
			b[i]=c[i];
		}
		for(int i=0;i<n/2;i++)
		{
			if(b[i]!=b[n-1-i])
			{
				e++;
			}
		}
		cout<<e*g;
	}
	return 0;
}
