#include<bits/stdc++.h>
#define Code using
#define by namespace
#define wjb std
Code by wjb;
#define int long long
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=5e5+10;
int n,m,a[N];
bool check(int x)
{
	int now=0,minn=0;
	for(int i=1;i<=x;i++)now+=a[x]-a[i];
	minn=now;
	for(int i=x+1;i<=n;i++)
	{
		now-=a[i-1]-a[i-x];
		now+=(x-1)*(a[i]-a[i-1]);
		minn=min(minn,now);
	}
	return minn<=m;
}
signed main()
{
//	system("fc crystal4.ans crystal.out");return 0;
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)a[i]=in();
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	out(ans);
	return 0;
}
