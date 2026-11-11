/*
	CSP-S 2026 RP++
	
	先排序 
	对于第 i 个数
	找到一个最小的 j<i 使得 (i-j+1)*a[i]-(sum[i]-sum[j-1])<=m
	考虑对 j 求 i
	即向右找到一个最大的 i>j 使得  (i-j+1)*a[i]-(sum[i]-sum[j-1]) 最小
	二分即可 
	
	初中最后一舞
	加油！ 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int GI=1<<20;
char *p1,*p2,buf[GI];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,GI,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int x=0,f=1;char ch=nc();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=nc();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=nc();
	return x*f;
}
const int maxn=5e5+7;
int n,m,a[maxn],sum[maxn];
bool check(int i,int j)
{
	return (i-j+1)*a[i]-(sum[i]-sum[j-1])<=m;
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int l=i+1,r=n,res=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid,i)) l=mid+1,res=mid;
			else r=mid-1;  
		}
		ans=max(ans,res-i+1);
	}
	cout<<ans;
	return 0;
}

