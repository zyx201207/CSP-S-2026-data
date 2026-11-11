#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int myread()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void prin(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) prin(x/10);
	putchar(x%10+'0');
}

const int MAXN=1000006;

int n,m;
int a[MAXN];
int cnt[MAXN];
int lis[MAXN];
int fa[MAXN];
int s[MAXN];
int tot;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	n=myread(); m=myread();
	for (int i=1;i<=n;i++) a[i]=myread();
	
	for (int i=n;i>=1;i--)
	{
		cnt[a[i]]++;
		if (cnt[a[i]]==1)
		{
			lis[++tot]=a[i];
			fa[a[i]]=a[i+1];
		}
		s[a[i]]++;
	}
	
	for (int i=m;i>=2;i--) s[fa[lis[i]]]+=s[lis[i]];
	for (int i=1;i<=m;i++)
	{
		prin(s[i]);
		putchar(' ');
	}
	
	return 0;
}
