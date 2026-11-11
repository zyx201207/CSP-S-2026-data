#include<bits/stdc++.h>
using namespace std;
long long read()
{
	int fu=1;
	long long res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return fu*res;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<=9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+5;
long long n,m,a[N];
long long d[N],f[N];
int cnt[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	f[1]=0;
	cnt[1]=0;
	for(int i=2;i<=n;i++)
	{
		cnt[i]=cnt[i-1]+1;
		f[i]=f[i-1]+d[i]*cnt[i];
		if(f[i]>m)
		{
			int l=0,r=cnt[i],mid;
			while(l<r)
			{
				mid=(l+r+1)/2;
				if(f[i]-(a[i]-a[i-mid])<=m) l=mid;
				else r=mid-1;
			}
			cnt[i]=l;
			f[i]-=a[i]-a[i-cnt[i]];
//			while(f[i]>m)
//			{
//				f[i]-=a[i]-a[i-cnt[i]];
//				cnt[i]--;
//			}//二分优化 
		}
		//cout<<i<<' '<<f[i]<<' '<<cnt[i]<<endl;
		ans=max(ans,cnt[i]);
	}
	write(ans+1);
	return 0;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7