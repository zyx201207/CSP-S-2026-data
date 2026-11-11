#include<bits/stdc++.h>
using namespace std;
string c;
bool f(string c)
{
	long long m=c.size();
	for(int i=0;i<m/2;i++)
	{
		if(c[i]!=c[m-i-1])return 0;
	}
	return 1;
}
int g(string c)
{
	long long cnt=0,m=c.size();
	for(int i=0;i<m/2;i++)
	{
		if(c[i]!=c[m-i-1])cnt++;
	}
	return cnt;
}
int main()
{
    long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			c+=a;
		}
	}
	if(f(c))
	{
		cout<<0;
		return 0;
	}
	cout<<g(c);
	return 0;
} 
