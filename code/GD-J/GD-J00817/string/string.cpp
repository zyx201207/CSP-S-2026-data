#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
bool pd(string s)
{
	int len=s.size();
	for(int i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len-i])
		{
			return false;
		}
	}
	return true;
}
int diff(string s)
{
	int len=s.size(),cnt=1;
	for(int i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len-i])
		{
			cnt++;
		}
	}
	return cnt;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	char s1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s1;
		for(int j=1;j<=a[i];j++)
		{
			s+=s1;
		}
	}
	if(pd(s))
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<diff(s)<<endl;
	}
	return 0;
}
