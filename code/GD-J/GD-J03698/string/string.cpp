#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long f(string s)
{
	long long sum=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			sum++;
		}
	}
	return sum;
} 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s="";
	cin>>n;
	while(n--)
	{
		long long a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	cout<<f(s);
	return 0;
 } 
