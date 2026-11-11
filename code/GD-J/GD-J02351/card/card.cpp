#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],f;
string s;
char b;
int check2(char x)
{
	for(int i=0;i<s.size();i++)
	{
		if(x==s[i])
		{
			f=i;
			return 1;
		} 
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		s+=b;
	}
	for(int i=1;i<=n;i++)
	{
		string s2="";
		for(int j=i;j<=n;j++)
		{
			s2+=s[i];
		}
		f=0;
		for(int i=0;i<s2.size();i++)
		{
			if(check2(s[i]))
			{
				s.erase(f,s2.size()-f);
			}
		}
		for(int i=0;i<s2.size();i++)
		{
			int t=s2[i]-48;
			a[t]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
