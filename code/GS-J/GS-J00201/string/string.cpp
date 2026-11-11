#include<bits/stdc++.h>
using namespace std;
long long ans=0,q,n;
char w;
string s="";
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>q>>w;
		for(int j=0;j<q;j++)
		{
			s+=w;
		}
	}
	long long e=0,r=0;
	e=s.size();
	if(e%2!=0)
	{
		r=(e-1)/2;
	}
	else
	{
		r=e/2;
	}
	for(int i=0;i<r;i++)
	{	
		if(s[i]!=s[e-i-1])
		{	
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
