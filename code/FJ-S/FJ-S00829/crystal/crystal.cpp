#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,ans=1,ax[500010],sum[500010];
void read(int &n)
{
	int ax=0,t=1;
	char ch=getchar();
	while (!(ch>='0'&&ch<='9'))
	{
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		ax=ax*10+ch-'0';
		ch=getchar();
	}
	n=ax*t;
	return;
}
void write(int n,char end='\n')
{
	vector<char> ax;
	if(n==0)
	{
		putchar('0');
		putchar(end);
		return;
	}
	if(n<0)
	{
		putchar('-');
		n=-n;
	}
	while (n!=0)
	{
		ax.push_back(n%10+'0');
		n/=10;
	}
	int cn=ax.size();
	for (int i=cn-1;i>=0;--i)
	  putchar(ax[i]);
	putchar(end);
	return;
}
bool check(int an,int x)
{
	int l=1,r=x-1;
	while (l<r)
	{
		int mid=l+r>>1;
		if(((x-mid)*an-(sum[x-1]-sum[mid-1]))<=m) r=mid;
		else l=mid+1;
	}
	if(((x-l)*an-(sum[x-1]-sum[l-1]))>m) return false;
	else
	{
		if(an==ax[x]) ans=max(ans,x-l+1);
		else ans=max(ans,x-l);
		return true;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;++i)
	  read(ax[i]);
	sort(ax+1,ax+n+1);
	for (int i=1;i<=n;++i)
	  sum[i]+=sum[i-1]+ax[i];
	for (int i=2;i<=n;++i)
	{
		int l=ax[i-1],r=ax[i];
		while (l<r)
		{
			int mid=l+r+1>>1;
			if(check(mid,i)==true) l=mid;
			else r=mid-1;
		}
		check(l,i);
	}
	write(ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
