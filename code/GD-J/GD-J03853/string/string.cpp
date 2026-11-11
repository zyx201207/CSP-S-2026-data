#include <bits/stdc++.h>
using namespace std;
char s[200005];
long long n,m[200005],x,z;
string c,v;
bool f=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>m[i]>>s[i];
		for(int j = 1;j<=m[i];j++)
		{
			c+=s[i];
		}
	}
	for(int i = 0,j=c.size()-1;i<=j;i++,j--)
	{
		if(c[i]!=c[j])
		{
			z++;
		}
	}
	cout<<z;
	return 0;
}
//Àî¼Î¾þ GD-J03853
