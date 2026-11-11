#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int n,m,ma=INT_MIN,a[N],c[30];
bool f[N];
bool zheng(int n)
{
	double d=log2(n);
	if(d==int(d)) return 1;
	return 0;
}
bool ci()
{
	for(int i=1;i<=n;i++)
	{
		if(!zheng(a[i]+1)) return 0;
	}
	return 1;
}
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int n,int k)
{
	if(k-1==n)
	{
		int cnt=0,sum=INT_MAX;
		for(int i=1;i<=n;i++) if(c[i]) cnt++,sum&=c[i];
		if(cnt!=m) return;
		ma=max(ma,sum);
		return;
	}
	dfs(n,k+1);
	c[k]=a[k];
	dfs(n,k+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n)
	{
		int sum=INT_MAX;
		for(int i=1;i<=n;i++)
			sum&=a[i];
		ma=sum;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
			ma=max(ma,a[i]);
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ma=max(ma,a[i]&a[j]);
	}
	else if(ci()) 
	{
		int sum=INT_MAX;
		for(int i=n;i>=n-m+1;i--)
			sum&=a[i];
		ma=sum;
	}
	else dfs(n,1);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
