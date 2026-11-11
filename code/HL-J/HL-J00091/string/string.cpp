#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
		char b[n];
		string x;
		long long t[n];
		long long z=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t[i]=0;	
	}
	long long tt=0,ff=n-1;
	 while(ff-tt>=0)
	{
		if(a[tt]!=a[ff])
		{
		for(long long j=0;j<a[tt];j++)
		x+=b[tt];
		t[ff]=1;
		}
		else
		if(b[tt]!=b[ff]&&a[tt]==a[ff])
		z+=a[tt];
		tt++;
		ff--;
	}
	for(long long i=0;i<n;i++)
	{
		if(t[i]==1)
		for(long long j=0;j<a[i];j++)
		x+=b[i];
	}
	long long w=x.size();
	long long v1=0,vn=w-1;
	while(vn-v1>=0)
	{
		if(x[v1]!=x[vn])
		z++;
		v1++;
		vn--;
	}
	cout<<z;
	return 0;
}