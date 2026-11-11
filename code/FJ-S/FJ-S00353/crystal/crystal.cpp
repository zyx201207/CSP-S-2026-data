#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar('0'+z[i]);}}
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
int ans;
inline int check(int l,int r,int z)
{
	return z*(r-l+1)-(sum[r]-sum[l-1]);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(); 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,best=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i,a[i])<=m)
			{
				best=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-best+1);
	}
	write(ans);
	
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
