#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1;
void dfs(int num,int aa,long long sum)
{
	if(aa+(m-num)>n)
	{
		return ;
	}
	if(num==m)
	{
		maxx=max(maxx,sum);
		return ;
	 } 
	 for(int i=aa+1;i+m-num-1<=n;i++)
	 {
	 	dfs(num+1,i,sum&a[i]);
	 	if(maxx!=-1)
	 	{
	 		return ;
		 }
	 }
}
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m+1;i++)
	{
		dfs(1,i,a[i]);
	}
	cout<<maxx;
	return 0;
}
