#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cs=0;
	long long s_len=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>c;
		for(long long j=0;j<a;j++)
		{
			s+=c;
		}
		s_len+=a;
	}
	for(long long i=0;i<s_len/2;i++)
	{
		if(s[i]!=s[s_len-i-1])
		{
			cs++;
		}
	}
	cout<<cs;
	return 0;
}
