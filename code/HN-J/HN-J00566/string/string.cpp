#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[199999]={};
	int n;
	cin>>n;
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		long long g;
		char z;
		cin>>g>>z;
		for(long long j=cnt+1;j<=g+cnt;j++)
		{
			a[j]=(int)z;
		}
		cnt+=g;
	}
		int l=1;
	long long gg=0;
	while(l<=cnt/2 && cnt>=cnt/2)
	{
		if(a[l]!=a[cnt])
		{
			gg++;
		}
		l++;
		cnt--;
	} 
	cout<<gg;
	return 0;
}
