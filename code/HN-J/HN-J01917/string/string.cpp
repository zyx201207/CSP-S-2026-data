#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f=1,sum,sum1;
string s;
string sa,sb;
char ag;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		cin>>ag;
		for(int i=1;i<=m;i++)
		{
			s[f]=ag;
			f++;
		}
	}
	for(int i=1;i<=f;i++)
	{
		cout<<s[i];
	}
	if(f%2==0)
	{
	for(int i=1;i<=f;i++)
	    {
		    if(i>=f/2) sa[i]=s[i];
		    else sb[i-sa.size()]=s[i];
	    }
    }
    else
    {
    	for(int i=1;i<=f;i++)
	    {
		    if(i>f) sa[i]=s[i];
		    else sb[i-sa.size()-1]=s[i];
	    }
    }
	
	for(int i=1;i<=sa.size();i++)
	    {
		    sum+=sa[i]!=sb[i]?1:0;

	    }
	    for(int i=1;i<=sb.size();i++)
	    {
		    sum1+=sb[i]!=sa[i]?1:0;
	    }
	    cout<<0;
	return 0;
 } 
