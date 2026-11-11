#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+5;
int n,a[M];
char c[M];
string s2(string s)
{
	int len=s.size();
	string s1;
		for(int i=len-1;i>=len/2;i--)
		{
		s1+=s[i];	
		}
		return s1;
}
bool check(string s)
{
	int len=s.size();
	string s1;
	if(len%2==0)
	{
		s1=s2(s);
		int cnt=0;
		for(int i=0;i<len/2;i++)
		{
			if(s[i]==s1[i]) cnt++;
		}
		if(cnt==len/2) return 1;
		else return 0;
	}
	else
	{
		s1=s2(s);
		int cnt=0;
		for(int i=0;i<=len/2;i++)
		{
			if(s[i]==s1[i]) cnt++;
		}
		if(cnt==len/2+1) return 1;
		else return 0;
	}
}   
string s,s1;                            
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int len=s.size();
	if(check(s))
	{
		
		cout<<0;
		return 0; 
	}
		s1=s2(s);
		int cnt=0;
		if(len%2)
		{
			for(int i=0;i<=len/2;i++)
		    {
			 if(s1[i]!=s[i]) cnt++;
		    }
		}
		else
		for(int i=0;i<len/2;i++)
		    {
			 if(s1[i]!=s[i]) cnt++;
		    }
		    cout<<cnt;
	return 0;
}
