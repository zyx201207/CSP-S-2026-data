#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,a,cnt=0;
	string s,m;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) 
		{
			s+=c;
		}
	}
	for(int i=s.size();i>=1;i--)
	{
		m+=s[i];
	}
	if(s==m)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=s.size();i++)
		{
			if(m[i]!=s[i])
			{
				m[i]=s[i];
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
	
}
