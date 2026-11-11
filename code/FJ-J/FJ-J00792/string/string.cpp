#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int b,d,s=0,m=0;
	char c;
	cin>>d;
	for(int i=1;i<=d;i++)
	{
		cin>>b>>c;
		s+=b;
		for(int i=1;i<=b;i++)
		{
			a+=b;
		}
	}
	for(int i=0;i<=d/2;i++)
	{
		if(a[i]!=a[s-1-i])
		{
			m++;
		}
	}
	cout<<m;
	return 0;
} 
