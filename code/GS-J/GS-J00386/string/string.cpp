#include<bits/stdc++.h>
using namespace std;
int cmp(string z)
{
	long long l=0;
	long long r=z.size()-1;
	long long m=0;
	while(l<r)
	{
		if(z[l]!=z[r])
		{
			z[r]=z[l];
			m++;
		}
		l++;
		r--;
	}
	return m;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	long long n;
	cin>>n;
	string s;
	while(n--)
	{
		long long a;
		string b;
		cin>>a;
		cin>>b;
		for(int i=0;i<a;++i)
		{
			s=s+b;
		}
	}
	cout<<cmp(s);
	return 0;
}
