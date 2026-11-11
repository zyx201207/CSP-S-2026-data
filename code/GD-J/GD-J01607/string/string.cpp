#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b,d=1,f=0;
char e;
string c;
int as(){
	for(int i=1;i<=d/2;i++)
	{
		if(c[i]!=c[d+1-i])
		{
			f++;
		}
	}
	return f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b>>e;
		for(;b;b--)
		{
			c[d]=e;
			d++;
		}
	}
	cout<<as()-1;
	return 0;
}
