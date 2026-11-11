#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,a;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a;
		cin>>c;
		for(long long j=0;j<a;j++)
		{
			s=s+c;
		}
	}
	long long b=s.size()/2;
	long long d=s.size()-1;
	long long cnt=0;
	for(long long i=d;i>b;i--)
	{
		if(s[i]==s[i-d])
		{
			d=d-2;
			continue;
		}
		else
		{
			cnt++;
			d=d-2;
		}
	}
	cout<<cnt;
	return 0;
}
