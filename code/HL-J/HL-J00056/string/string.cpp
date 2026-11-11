#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],cnt;
char c[200010];
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}	
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		s1+=s[i];
	}
	for(int i=0;i<=(s.size()-i-1);i++)
	{
		if(s[i]!=s1[i])
		{
			cnt++; 
		} 
	}
	cout<<cnt;
	return 0;
}
