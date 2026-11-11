#include <bits/stdc++.h>
using namespace std;
long long hw(string s)
{
	long long sum=0;
	long long len=s.size();
	for(long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i]) sum++;
	}
	return sum;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin>>n;
	while(n--)
	{
		long long k;
		string r;
		cin>>k>>r;
		for(long long i=1;i<=k;i++)
		{
			s+=r;
		}
	}
	cout<<hw(s);
	
	return 0;
}
