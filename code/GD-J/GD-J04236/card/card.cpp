#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ci[300005];
char c[500005];
string s,s1,s2="";
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		s+=c[i];
	}
	s1=s;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=s.size()-1;j++)
		{
			if(s1.find(s[j])==-1)
		    {
			    s1+=s[j];
		    }
		    else
		    {
			    for(int k=0;k<=s1.find(s[j]);k++)
			    {
				    s2+=s1[k];
			    }
			    s1=s2;
			    s2="";
		    }
		}
		for(int j=0;j<=s.size()-1;j++)
		{
			if(s1.find(s[j]))
			{
				ci[(s[j]-'0')]+=1;
			}
		}
		s1=s;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ci[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
