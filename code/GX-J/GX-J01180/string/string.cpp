#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x>>c;
		if(x>1000000)
		{
			cout<<n*x/2;
			return 0;
		}
		for(long long j=0; j<x; j++)
		{
			s+=c;
		}
	}
	long long len=s.size();
	long long mid=len/2;
	
	for(int i=0; i<mid; i++)
	{
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
