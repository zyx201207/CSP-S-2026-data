#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

ll myread()
{
	ll x=0,f=1;
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
const ll INF12=1000000000000;

ll n,m;
ll a[MAXN];
ll s[MAXN];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=myread(); m=myread();
	for (int i=1;i<=n;i++) a[i]=myread();
	for (int i=1;i<=n;i++) a[i]+=INF12+1;
	
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ans=0;
	for (int r=1,l=1;r<=n;r++)
	{
		while (l<r&&a[r]*(r-l+1)-(s[r]-s[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	prin(ans);
	
	return 0;
}
