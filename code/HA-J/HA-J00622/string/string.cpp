#include <bits/stdc++.h>
using namespace std;
long long n,ji;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		long long shu;
		char w;
		cin>>shu>>w;
		for(int i=1;i<=shu;i++)
		{
			s+=w;
		}
	}
	long long l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			ji++;
		}
		l++;
		r--;
	}
	cout<<ji;
	return 0;
}
