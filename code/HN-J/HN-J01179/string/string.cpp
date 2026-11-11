#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,v=0;
	cin>>n;
	string s,h;
	for(long long i=1;i<=n;i++)
	{
		long long t;
		char m;
		cin>>t>>m;
		for(long long j=1;j<=t;j++)
		{
			s+=m;
			v++;
		}
	}
	for(long long i=v-1;i>=0;i--)
	{
		h+=s[i];
	}
	long long ant=0;
	for(long long i=0;i<v/2;i++)
	{
		if(h[i]!=s[i])
		{
			ant++;
			s[i]=h[i];
		}
	}
	cout<<ant;
	return 0;
}
