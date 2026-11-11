#include<bits/stdc++.h>
using namespace std;
char a[130000];
int main()
{
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	long  n;
	cin>>n;
   long long  k=0;
	for(long long i=1;i<=n;i++)
	{
		long long c;
		char b;
		cin>>c>>b;
		for(long long j=1;j<=c;j++)
		{
			a[j+k]=b;
			
		}
		k+=c;
		
	}
//	for(int i=1;i<=k;i++)
//	{
//		cout<<a[i]<<" ";
//	}
for(long long i=1;i<=k/2;i++)
{
	if(a[i]!=a[k-i])
	{
	sum++;	
	}
}
cout<<sum;
}
