#include<bits/stdc++.h>
using namespace std;
struct x
{
	long long a;
	char c;
};
x g[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0;
	cin>>n;
	long long t=1,w=n;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i].a>>g[i].c;
	}
	while(t<w)
	{
		if(g[t].a>g[w].a)
		{
			g[t].a=g[t].a-g[w].a;
			if(g[t].c!=g[w].c)
			{
				num+=g[w].a;
			}
			w--;
			continue;
		}
		if(g[t].a==g[w].a)
		{
			if(g[t].c!=g[w].c)
			{
				num+=g[w].a;
			}
			t++;
			w--;
			continue;
		}
		if(g[t].a<g[w].a)
		{
			g[w].a=g[w].a-g[t].a;
			if(g[t].c!=g[w].c)
			{
				num+=g[t].a;
			}
			t++;
			continue;
		}	
	}
	cout<<num;
	return 0;
}
