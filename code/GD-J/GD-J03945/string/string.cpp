#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
	int cnt=0;
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(s.size()%2){
			if(s[i]!=s[s.size()-i+1])
			{
				cnt++;
			}
		}
		else
		{
			if(s[i]!=s[s.size()-i])
			{
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int l;
		string a;
		cin>>l>>a;
		for(int j=1;j<=l;j++)
		{
			s+=a;
		}
	}
	bool flag=1;
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(s.size()%2){
			if(s[i]!=s[s.size()-i+1])
			{
				flag=0;
			}
		}
		else
		{
			if(s[i]!=s[s.size()-i])
			{
				flag=0;
			}
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	cout<<check(s);
	return 0;
}

