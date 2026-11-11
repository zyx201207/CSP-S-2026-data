#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	long n = 0;
	long long a = 0;
	string c = " ";
	char in;
	long long l = 0;
	cin>>n;
	for(long long i = 1;i <= n;i++)
	{
		a = 0;
		cin>>a;
		cin>>in;
		for(long long j = 1;j <= a;j++)
		{
			c += in;
			l++;
		} 
	}
	
	
	for(long long i = 1;i <= l/2;i++)
	{
		if(c[i] != c[l-i+1]) 
		{
			ans++;	
		}
	}
	cout<<ans;

	return 0;
} 
