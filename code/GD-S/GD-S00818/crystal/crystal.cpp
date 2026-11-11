#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 5e5+5;
int n,m;
int a[N];
int sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i = 1; i <= n; i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) sum[i]=sum[i-1]+a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1,r = i,res = i;
		while (l<=r)
		{
			int mid = (l+r)/2;
			if (a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m) r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	write(ans);
	return 0;
}

