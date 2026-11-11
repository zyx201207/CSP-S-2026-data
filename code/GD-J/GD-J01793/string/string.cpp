#include<bits/stdc++.h>
using namespace std;
int n;
string s;

string pin(string s3,int x,string s4)
{
	while(x>0)
	{
		if(x%2==1)
		{
			s3+=s4;
		}
		s4=s4+s4;
		x/=2;
	}
	return s3;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		string s1;
		cin>>k>>s1;
		s=pin(s,k,s1);
	}
	int cnt=0;
	for(int i=0;i<s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;	
}
