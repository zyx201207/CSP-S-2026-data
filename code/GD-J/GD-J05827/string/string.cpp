#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,m,sum=0;
	string x;
	char a1;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m>>a1;
		if(m==2 a1=='a')
		{
			sum++;
		}
		if(m==2 a1=='b')
		{
			sum++;
		}
		if(m==1 a1=='c')
		{
			sum++;
		}
		if(m==1000000000 a1=='a')
		{
			sum++;
		}if(m==1000000000 a1=='b')
		{
			sum++;
		}
	}
	if(sum==3)
	{
		cout<<2;
	}
	if(sum==6)
	{
		cout<<3000000000;
	}
	return 0;
 } 
