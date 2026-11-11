#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int n,m;
int a[N];
int sa[N];
int anss=0;
bool check(int x,int y)
{
	int judge=(y-x)*a[y]-(sa[y-1]-sa[x-1]);
	if(judge<=m)
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();
	m=in();
	for(int i=1;i<=n;i++)
	{
		a[i]=in();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sa[i]=sa[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int mid=0;
		
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid,i))
			{
				r=mid-1;
				anss=max(anss,i-mid+1);
			}
			else
			{
				l=mid+1;
			}
		}
	}
	out(anss);
	return 0;
}

