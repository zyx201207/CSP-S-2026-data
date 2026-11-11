#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
long long ans=0;
void dfs(long long sum,long long num,int s)
{
	if(num==0)
	{
		return ;
	}
	if(sum>n&&s==m)
	{
		ans=max(ans,num);
		return ;
	}
	if(sum>n||s>m)
	{
		return ;
	}
	dfs(sum+1,num&a[sum],s+1);
	dfs(sum+1,num,s);
}
bool cmp(long x,long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	 } 
	 if(m==1)
	 {
	 	cout<<maxn;
	 	return 0;
	 }
	 maxn=0;
	 if(m==2)
	 {
	 	for(int i=1;i<=n;i++)
	 	{
	 		for(int j=1;j<=n;j++)
	 		{
	 			if(i!=j)
	 			{
	 				maxn=max(maxn,a[i]&a[j]);
				 }
			 }
		 }
		 cout<<maxn;
		 return 0;
	 }
	 maxn=a[1];
	 if(m==n)
	 {
	 	for(int i=2;i<=n;i++)
	 	{
	 		maxn=maxn&a[i];
		 }
		 cout<<maxn;
		 return 0;
	 }
	 if(m==n-1)
	 {
	 	sort(a+1,a+n+1,cmp);
	 	maxn=a[1];
	 	for(int i=2;i<n;i++)
	 	{
	 		maxn=maxn&a[i];
		 }
		 cout<<maxn;
		 return 0;
	 }
	 if(n<=2000)
	 {
	 	for(int i=1;i<=n-m+1;i++)
		{
			dfs(i+1,a[i],1);
		}
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		maxn=a[1];
		for(int i=2;i<=m;i++)
		{
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	cout<<ans;
	return 0;
}
