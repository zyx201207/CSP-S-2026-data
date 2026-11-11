#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct aaa
{
	int gss;
	string zmm;
}aaa[200900];
string s;
string s1,s2;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		cin>>aaa[i].gss>>aaa[i].zmm;
		for(int j=1;j<=aaa[i].gss;j++)
		{
			s=s+aaa[i].zmm;
		}
		ss=ss+aaa[i].gss;
	}
	int bj=0;
	if(ss%2==0)
	{
		ss=ss/2;
	}
	else
	{
		ss=ss/2+1;	
		bj=1;
	}
	int ans=0;
	if(bj==1)
	{
		for(int i=0;i<ss-1;i++)
		{
			s1=s1+s[i];
		}
		s1=" "+s1;
		for(int i=ss;i<=s.size();i++)
		{
			s2=s[i]+s2;
		}
		for(int i=1;i<ss;i++)
		{
			if(s1[i]!=s2[i])
			{
				ans++;
			} 
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=0;i<ss;i++)
		{
			s1=s1+s[i];
		}
		s1=" "+s1;
		for(int i=ss;i<=s.size();i++)
		{
			s2=s[i]+s2;
		}
		for(int i=1;i<ss+2;i++)
		{
			if(s1[i]!=s2[i])
			{
				ans++;
			} 
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
