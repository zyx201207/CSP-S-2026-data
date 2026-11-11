#include <bits/stdc++.h>
using namespace std;
int n,a;
long long cnt=0;
char c;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		s1+=s[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
