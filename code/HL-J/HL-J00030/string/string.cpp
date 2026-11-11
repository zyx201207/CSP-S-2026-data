#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s)
	{
		cout<<0;
		return 0;
	} 
	int cnt=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]!=s[s.size()-i])
		{
			s[i]=s[s.size()-i];
			cnt++;
		} 
		s2=s;
		reverse(s2.begin(),s2.end());
		if(s2==s)
		{
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}
