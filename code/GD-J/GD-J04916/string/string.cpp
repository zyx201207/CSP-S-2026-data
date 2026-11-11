#include<bits/stdc++.h>
using  namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	string b="";
	for(long long i=0;i<=n-1;i++)
	{
		long long a;
		char c;
		cin>>a;
		cin>>c;
		for(long long j=0;j<=a-1;j++)
		{
			b+=c;
		}
		
	}
	long long l=b.length();
	for(long long i=0;i<=(l+1)/2;i++)
	{
		if(b[i]==b[l-i-1])
			continue;
		else
		{
			b[l-i-1]=b[i];
			cnt++;
		}					
	}
	cout<<cnt;
	return 0;
}
