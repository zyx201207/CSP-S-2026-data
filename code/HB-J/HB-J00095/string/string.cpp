#include<bits/stdc++.h>
using namespace std;
char q[30000000],p[30000000];
int b=0,t=0;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			q[b]=c;
			b++;
		}
	}
	int a=0;
	for(int i=b-1;i>=0;i--)
	{
		p[a]=q[i];
		a++;
	}
	for(int i=0;i<b;i++)
	{
		a--;
		if(p[i]!=q[i])
		{
			p[i]=q[i];
			q[a]=q[i];
			t++;
		}
	}
	cout<<t;
	return 0;
}
