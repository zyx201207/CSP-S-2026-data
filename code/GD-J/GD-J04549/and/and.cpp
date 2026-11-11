#include<bits/stdc++.h>
using namespace std;
long long n,m,a,maxn,maxnn,aa;
string s[100005];
long long h(long long aaa)
{
	long long aaaa=1;
	if(aaa=1) return 1;
	for(long long g=0;;g+=0)
	{
		aaaa*=2;
		aaa-=1;
		if(aaa==0) break;
	}
	return aaaa;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) 
	{
		cin>>a;
		for(long long g=0;;g+=0)
		{
			if(a%2==0) s[i]+='0';
			else 
				s[i]+='1';
			a/=2;
			if(a==0) break;
		}
		if(s[i].size()>maxn) maxn=s[i].size();
	}
	for(long long i=0;i<n;i++)
	{
		for(long long g=0;;g+=0)
		{
			if(s[i].size()==maxn) break;
			s[i]='0'+s[i];
		}
	}
	for(long long i=0;i<maxn;i++)
	{
		aa=0;
		for(long long j=0;j<n;j++)
		{
			string e=s[i];
			if(e[j]=='1') aa++;
		}
		if(aa>m) maxnn+=h(n-i+1);
	}
	cout<<maxnn;
	return 0;
}
