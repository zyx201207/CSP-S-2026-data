#include <bits/stdc++.h>
using namespace std;
int k(string p)
{
	bool o=true;
	int u=0;
	for(int i=0;i<=p.size()/2;i++)
	{
		if(p[i]!=p[p.size()-1-i])
		{
			u++;
		}
	}
	return u;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	int n;
	string s;
	string b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	cout<<k(s);
	return 0;
} 
