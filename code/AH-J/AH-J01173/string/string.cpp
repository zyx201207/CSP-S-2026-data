#include<bits/stdc++.h>
using namespace std;
long long e,f,g;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	char d[8300000];
	int b=0;
	char c;
	for(int i=0;i<a;i++)
	{
		int p=b;
		cin>>b>>c;
		e=e+b;
		for(int y=p;y<p+b;y++)
		{
			d[y]=c;
		}
	}
	f=e/2;
	for(int i=0;i<f;i++)
	{
		if(d[i]!=d[e-i-1])
		{
		g++;
		}
	}
	cout<<g;
	return 0;
}
