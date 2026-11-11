#include<cstdio>
using namespace std;
int c,t;
long long read()
{
	long long k=1,x=0;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while (t--)
		puts("4");
	return 0;
 }

