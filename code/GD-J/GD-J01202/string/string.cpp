#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	long long n,cnt=0,l,r;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long s1;
		char c;
		cin>>s1>>c;
		for(long long j=1;j<=s1;j++)
		{
			s+=c;
		}
	}
	l=0;
	r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
} 
