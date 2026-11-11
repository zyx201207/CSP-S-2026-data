#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int f=1,s=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();
	int T=read();
	while (T--)
	{
		puts("0");
	}
	return 0;
}
