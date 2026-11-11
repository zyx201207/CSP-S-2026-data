#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int l[N],r[N];
char c[N];
int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar((x%10)^48);
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read(),sum=1;
	for(int i=1;i<=n;i++)
	{
		int a=read();
		char ch=0;
		while(ch<'a'||ch>'z') ch=getchar();
		l[i]=sum;
		r[i]=sum+a-1;
		c[i]=ch;
		sum+=a;
	}
	sum--;
	int ans=0,mid=sum/2;
	for(int i=1;i<=n&&l[i]<=(sum>>1);i++)
	{
		int nl=upper_bound(l+1,l+n+1,sum+1-min(r[i],mid))-l-1,nr=lower_bound(r+1,r+n+1,sum+1-l[i])-r;
		for(int j=nl;j<=nr;j++)
		{
			if(c[j]!=c[i])
			{
				int ansl=max(sum+1-min(r[i],mid),l[j]),ansr=min(sum+1-l[i],r[j]);
				ans+=ansr-ansl+1;
			}
		}
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
