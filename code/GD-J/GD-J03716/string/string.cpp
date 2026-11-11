#include<bits/stdc++.h>
using namespace std;
typedef long long l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	l n,cnt=0;
	cin>>n;
	string s="",d="";
	for(l i=1;i<=n;i++)
	{
		l a;
		char c;
		cin>>a>>c;
		for(l j=1;j<=a;j++)s+=c;
	}
	for(l i=0;i<s.size()/2;i++)
	{
		d+=s[i];
	}
	for(l i=0;i<d.size();i++)
	{
		if(d[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
}
