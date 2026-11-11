#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >>n;
	string s;
	for(int i=0;i<n;i++)
	{
		long long x;
		char y;
		cin >>x>>y;
		for(int j=0;j<x;j++) s+=y;
	}
	long long sum=0;
	long long a=0;
	long long b=s.size()-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[a]!=s[b]){
		   s[b]=s[a];
		   sum++;
		   a++;
		   b--;
	    }
	    else
	    {
	    	a++;
	    	b--;
		}
	}
	cout <<sum;
	return 0;
}
