#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
char x;
string z="",s;

string mo(string p)
{
	int t=p.size()-1;
	string k="";
	for(int i=0;i<p.size();i++)
	{
		k+=p[t];
		t--;
	}
	return k;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>x;
		for(int i=1;i<=m;i++)
		{
			z+=x;
		}
	}
	s=mo(z); 
	for(int i=0;i<=z.size()/2;i++)
	{
		if(z[i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}

