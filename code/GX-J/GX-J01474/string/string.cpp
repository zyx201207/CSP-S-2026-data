#include<bits/stdc++.h>
using namespace std;
long long a,c,d=1,e,f;
struct y
{
	long long a;
	char b;
}b[10000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	e=a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i].a>>b[i].b;
		c+=b[i].a;
	}
	while(c!=0&&d<e)
	{
		if(b[d].b!=b[e].b)
		{
			f+=min(b[d].a,b[e].a);
		}
		if(b[d].a<b[e].a)
		{
			b[e].a-=b[d].a;
			c-=b[d].a;
			b[d].a=0;
		}
		else
		{
			b[d].a-=b[e].a;
			c-=b[e].a;
			b[e].a=0;
		}
		if(b[d].a==0)
		{
			d++;
		}
		if(b[e].a==0)
		{
			e--;
		}
	}
	cout<<f;
	return 0;
}
