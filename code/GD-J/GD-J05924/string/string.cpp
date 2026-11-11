#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		char ch;
		cin>>t>>ch;
		for(int i=1;i<=t;i++)
		{
			s+=ch;
		}
	}
	long len=s.size();
	for(long long i=0;i<ceil(len/2);i++)
	{
		if(s[i]!=s[len-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
