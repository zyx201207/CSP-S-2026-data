#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string s,s1;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(s[0]!=s1[0]||s[1]!=s1[1])
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(('A'<=s[2]&&s[2]<='C'&&'A'<=s1[2]&&s1[2]<='C')||('D'<=s[2]&&s[2]<='F'&&'D'<=s1[2]&&s1[2]<='F'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s[2]-s1[2])==1)
	{
		cout<<1;
	}
	else cout<<"0";
	return 0;
}

