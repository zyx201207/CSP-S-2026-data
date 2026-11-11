#include<bits/stdc++.h>
using namespace std;
long long n,m=0,num=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		m+=x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	for(long long i=1;i<=m/2;i++)
	{
		if(s[i-1]!=s[m-i])
		{
			num++;
		}
	}
	
	cout<<num;
	
	
	return 0;
}
