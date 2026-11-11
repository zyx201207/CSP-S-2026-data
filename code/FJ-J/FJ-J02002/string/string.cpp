#include<bits/stdc++.h>
using namespace std;
string s="",h="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long x;
		char z;
		cin>>x>>z;
		while(x--)
		{
			s+=z;
		}
	}
	unsigned long long l=0;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			l++;
		}
	}
	cout<<l/2;
	return 0;
}
