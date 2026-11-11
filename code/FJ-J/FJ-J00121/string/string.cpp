#include<bits/stdc++.h>
using namespace std;
long long n;
string ss,ss_copy;
long long minv=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		string now_s;
		cin>>now_s;
		while(x--)
			ss+=now_s;
	}
	if((long long)ss.size()%2!=0)
	{
		long long half=(long long)(ss.size()+1)/2;
		ss_copy=ss.substr(half);
		ss=ss.substr(0,half-1);
	}
	else
	{
		long long half=(long long)ss.size()/2;
		ss_copy=ss.substr(half);
		ss=ss.substr(0,half);
	}
	for(long long i=0;i<(long long)ss.size();i++)
	{
		if(ss[i]!=ss_copy[i])
			minv++;
	}
	cout<<minv;
	return 0;
} 
