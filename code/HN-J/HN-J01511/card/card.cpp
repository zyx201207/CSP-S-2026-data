#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],last[300010],a_last[500010],num[300010],f;

void in(int &x)
{
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}

void out(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	in(n),in(m);
	for(int i=1;i<=n;i++) in(a[i]);
	for(int i=n;i>=1;i--)
	{
		if(!last[a[i]]) last[a[i]]=i;
		else if(!f) f=i+1;
		a_last[i]=last[a[i]];
	}
	if(!f) f=1;
	for(int i=1;i<=n;i++)
	{
		if(i==f) break;
		for(int j=i;j<=n;j++)
		{
			num[a[j]]++;
			j=a_last[j];
		}
	}
	for(int i=f;i<=n;i++) num[a[i]]+=i-f+1;
	for(int i=1;i<=m;i++) out(num[i]),putchar(' ');
	return 0;
}
