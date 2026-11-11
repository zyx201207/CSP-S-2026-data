#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[2000],s,z=0;
	long long n2;
	char c[2000];
	string f;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i]>>c[i];
		if(i==0)
		{
			s=a[i];
		}
		if(a[i]!=s)
		{
			z=1;
		}
		n2+=a[i];
		for(int j=0; j<a[i]; j++)
		{
			f+=c[i];
		}
	}
	if(z==0)
	{
		for(int i=0; i<n; i++)
		{
			a[i]=1;
		}
		n2=n;
	}
	int j=n,fl=0;
	for(long long i=0; i<n2/2; i++)
	{
		if(f[i]!=f[j--])
		{
			fl=1;
		}
	}
	if(fl==0)
	{
		cout<<0;
		return 0;
	}
	long long tot=0;
	for(int i=0; i<n; i++)
	{
		for(long long j=n2-a[i]; j<n2; j++)
		{
			if(f[j]!=c[i])
			{
				tot++;
			}
			f[j]=c[i];
		}
		n2-=a[i];
		int k=n,fl=0;
		for(long long j=0; j<n2/2; j++)
		{
			if(f[j]!=f[k--])
			{
				fl=1;
			}
		}
		if(fl==0)
		{
			if(z==0){
				cout<<tot*s;
			} else {
				cout<<tot;
			}
			return 0;
		}
	}
	cout<<tot;
	return 0;
}
