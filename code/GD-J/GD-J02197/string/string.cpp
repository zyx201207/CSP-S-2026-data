#include<bits/stdc++.h>
using namespace std;
char d[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,n2=1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long  n1;
		cin>>n1;
		char s;
		cin>>s;
		for(int i=n2;i<=n2+n1;i++)
		{
			d[i]=s;	
		}
		n2+=n1;
	}
	for(int i=1;i<=n2/2;i++)
	{
		if(d[i]!=d[n2-i])
		{
			sum++;
			
				
		}
	}
	cout<<sum;
	
		
	

	
	
	
	return 0;
}
