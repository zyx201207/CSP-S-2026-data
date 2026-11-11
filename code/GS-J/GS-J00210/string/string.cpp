#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s,r,x,a;
long long k;
bool check()
{
	int v=1;
	for(int i=s.size()-1;i>=1;i--)
	{
		r[i]=s[v];
		v++;
	}
	if(s==r)
	{
		return true;
	}
	return false;
}
void work()
{
	for(long long i=1;i<=k;i++)
	{
		a=a+x;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" "+s;
	r=" "+r;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		cin>>x;
		a=" "+a;
		work();
		s=s+x;
	}
	if(check())
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=s.size()-1;i++)
	{
		if(s[i]!=r[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
