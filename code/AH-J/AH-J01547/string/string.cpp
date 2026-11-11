#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,d,g,h;
	long long a,b,e,f=0;
	char c;
	cin>>a;
	for(long long i=1;i<=a;i++)
	{
		e=1;
		cin>>b>>c;
		g=c;
		while(e<=b)
		{
			h=g;
			g+=g;
			e*=2;
		}
		s+=h;
		if(e<b)
		{
			for(long long j=e+1;j<=b;j++)
			{
				s+=c;
			}
		}
	}
	if(s.size()/2==0)
	{
		d=s.substr(0,ceil((s.size()-1)/2.0)-1);
		s=s.substr(ceil((s.size()-1)/2.0)+1);
	}
	else
	{
		d=s.substr(0,ceil((s.size()-1)/2.0));
		s=s.substr(ceil((s.size()-1)/2.0)+1);
	}
	reverse(d.end(),d.begin());
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]!=d[i])
		{
			f++;
		}
	}
	cout<<f;
}
