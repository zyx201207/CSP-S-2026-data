#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010],d[500010];
inline long long read()
{
	long long x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,ans=0;
	n=read();
	cout<<n;
	return 0; 
}

