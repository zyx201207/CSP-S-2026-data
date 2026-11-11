#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int m;
	if(s.size()%2!=0)
	{
		m=s.size()/2+1;
		string s1,s2;
		int cnt=0;
		for(int i=0;i<m-1;i++)s1+=s[i];
		for(int i=s.size()-1;i>=m;i--)s2+=s[i];
		for(int i=0;i<=s1.size();i++)
		{
			if(s1[i]!=s2[i])cnt++;
		}
		cout<<cnt;
	}
	else
	{
		m=s.size()/2;
		string s1,s2;
		int cnt=0;
		for(int i=0;i<m;i++)s1+=s[i];
		for(int i=s.size()-1;i>=m;i--)s2+=s[i];
		for(int i=0;i<=s1.size();i++)
		{
			if(s1[i]!=s2[i])cnt++;
		}
		cout<<cnt;
	} 
	return 0; 
}
