#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],b[500010];
long long read()
{
	int k=1;
	long long ans=0;
	char c=getchar();
	while(c<'0'||c>'9') 
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans*k;
}
bool check(int x,int y)
{
	if(a[y]*(y-x+1)-(b[y]-b[x-1])<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(check(i,mid)) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
}
