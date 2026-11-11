#include<bits/stdc++.h>
using namespace std;
char b[200005];
int main()
{
	//freopen("string.in","u",stdin);
	//freopen("string.out","w",stdout);
	char c;
	int n,a;
	cin>>n;
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			b[y*a+j]=c;
		}
		y++;
		x+=a;
	}
	int v=0;
	for(int i=x;i<x/2;i++)
	{
		if(b[i]!=b[x-i+1])
			v++;
	}
	cout<<v;
	return 0;
}
