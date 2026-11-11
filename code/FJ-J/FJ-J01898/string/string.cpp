#include <bits/stdc++.h>
using namespace std;
string s;
long long n,k=0;
void check()
{
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		k++;
	}
	cout<<k;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long x; char y;
		cin>>x>>y;
		for(long long j=0;j<x;j++)
		s+=y;
	}
	check();
	return 0;

 } 
