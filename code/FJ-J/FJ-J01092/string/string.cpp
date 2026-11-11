#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int shu;
		char c;
		cin>>shu>>c;
		for(int i=1;i<=shu;i++)
		{
			s+=c;
		}
	}
	int l=1,r=n;
	int cnt=0;
	if(n%2==0)
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[l]!=s[r]) cnt++;
			l++;
			r--;
		}
	}
	else
	{
		for(int i=0;i<s.size()/2+1;i++)
		{
			if(s[l]!=s[r]) cnt++;
			l++;
			r--;
		}
	}
	cout<<cnt;
}  
