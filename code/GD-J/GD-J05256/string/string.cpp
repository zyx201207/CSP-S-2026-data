#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[200010];
	char b[200010];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	char b1[1000000010];
	long long z=1;
	for(long long i=1;i<=n;i++)
	{
		 for(long long j=z;j<=a[i]+z-1;j++)
		 {
		 	b1[j]=b[i];	
		 }
		 z+=a[i];
	}
	char b2[1000000010];
	long long o=0;
	for(long long i=z-1;i>=1;i--)
	{
		o++;
		b2[o]=b1[i];
	}
	long long zs=0;
	for(long long i=1;i<=o;i++)
	{
		if(b2[i]!=b1[i])
		{
			zs++;
		}
	}
	cout<<zs/2<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
