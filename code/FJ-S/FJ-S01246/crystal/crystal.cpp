#include<bits/stdc++.h>
#define il inline
#define int long long
#define pii pair<int,int>

using namespace std;
const int maxn=5e5+5;
int fli,n,m,sum[maxn],cfa[maxn],sm1[maxn],sm2[maxn],ans;
bool flb;
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		sum[i]=read();
		if(i!=1&&sum[i]-sum[i-1]!=sum[2]-sum[1])
			flb=0;
	}
	if(flb)
	{
		for(int i=1;i<=n;i++)
		{
			fli+=(i-i/2)*abs(sum[2]-sum[1]);
			if(m<fli)
			{
				printf("%lld\n",i-1);
				return 0;
			}
		}
		printf("%lld\n",n);
		return 0;
	}
	sort(sum+1,sum+n+1);
	for(int i=1;i<=n;i++)
		cfa[i]=sum[i]-sum[i-1];
	for(int i=1;i<=n;i++)
		sm1[i]=sm1[i-1]+cfa[i]*i;
	for(int i=n;i;i--)
		sm2[i]=sm2[i+1]+cfa[i]*(n+1-i);
	for(int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i);
		while(l<=r)
		{
			int mid=l+r>>1,rs1=sm1[i]-sm1[i-mid-1]-(i-mid)*(sum[i]-sum[i-mid-1]),rs2=sm2[i+1]-sm2[i+mid+2]-(n-i-mid)*(sum[i+mid+1]-sum[i]);
			if(rs1+rs2>m)
				r=mid-1;
			else
			{
				ans=max(ans,mid*2+1);
				l=mid+1;
			}				
		} 
	} 
	for(int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i-1);
		while(l<=r)
		{
			int mid=l+r>>1,rs1=sm1[i]-sm1[i-mid-1]-(i-mid)*(sum[i]-sum[i-mid-1]),rs2=sm2[i+2]-sm2[i+mid+3]-(n-1-i-mid)*(sum[i+mid+2]-sum[i+1]);
			if(rs1+rs2+(mid+1)*(sum[i+1]-sum[i])>m)
				r=mid-1;
			else
			{
				ans=max(ans,mid*2+2);
				l=mid+1;
			}				
		} 
	} 
	printf("%lld\n",ans);
	return 0;
}

