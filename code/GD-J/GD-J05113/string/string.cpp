#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long su=1;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		for(long long i=1;i<=x;i++)
		{
			s[su]=y;
			su++;
		}
	}
	su--;
	long long sum=0;
	for(long long i=1;i<=(su+1)/2;i++)
	{
		if(s[i]!=s[su+1-i])
			sum++;
	}
	cout<<sum;
}
