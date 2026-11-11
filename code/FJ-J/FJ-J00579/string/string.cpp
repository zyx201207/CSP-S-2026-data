#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("string.in");
	ofstream fout("string.out");
	long long n,j1,sum=0ll,ji=0ll;
	string s="";
	char j2;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>j1>>j2;
		for(int j=1;j<=j1;j++)
		{
			s+=j2;
		}
	}
	ji=s.size();
	j1=ji/2;
	for(long long i=0ll;i<j1;i++)
	{
		if(s[i]!=s[ji-i-1])
		{
			sum++;
		}
	}
	fout<<sum;
	return 0;
}
