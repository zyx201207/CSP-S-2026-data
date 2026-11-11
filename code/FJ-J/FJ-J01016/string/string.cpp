#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int e;
	long long p,tt=0;
	cin>>e;
	int s[e];
	string zm="",z[e];
	for(int i=0;i<e;i++)
	{
		cin>>s[i];
		cin>>z[i];
	}
	for(int i=0;i<e;i++)
	{
		for(int j=1;j<=s[i];j++)
		{
			zm+=z[i];
			p++;
		}
	}
	p-=1;
	for(int i=0;i<p/2;i++)
	{
		if(zm[i]!=zm[p-i-1])
		{
			tt++;
		}
	}
	cout<<tt;
	return 0;
}
