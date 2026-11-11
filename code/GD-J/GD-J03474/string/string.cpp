#include<bits/stdc++.h>
using namespace std;
string n,s;
char c;
int b,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for (int i=1;i<=a;i++)
	{
		cin >> b >> c;
		for (int j=1;j<=b;j++)
		{
			n+=c;
		}
	}
	b=0;
	for (int i=n.size()-1;i>=0;i--)
	{
		s+=n[i];
	}
	for (int i=0;i<n.size();i++)
	{
		if (n[i]!=s[i])
		{
			b+=1;
		}
	}
	cout << b/2 << endl;
	return 0;
} 
