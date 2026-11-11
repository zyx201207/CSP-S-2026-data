#include <bits/stdc++.h>
using namespace std;
int a,m;
long long b,p;
string c,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b>>c;
		p+=b;
		for(int j=1;j<=b;j++)
		{
			d+=c;
		} 
	}
	for(int i=0;i<p/2;i++)
	{
		if(d[i]!=d[p-i-1])
		{
			m++;
		}
	}
	cout<<m;
	return 0;
}
