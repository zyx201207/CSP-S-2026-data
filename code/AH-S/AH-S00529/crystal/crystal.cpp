#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long s=0;
	char ch=getchar(),f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n=read();
	long long m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int ans=1;
	for(int i=n;i>=1;i--)
	{
		int l=1,r=i-1;
		long long v=a[i]-a[i-1];
		int s=0;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if(v*(i-mid)-a[i-1]+a[mid-1]<=m) s=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,s);
	}
	write(ans);
	return 0;
}
