#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum;
bool cmp(long long a,long long b)
{
	return a>b;
}
void dfs(int deep,long long ans,int where)
{
	if(deep==m)
	{
		sum=max(sum,ans);
		return ;
	}
	else if(where==n) return ;
	dfs(deep+1,(ans==0 ? a[where]:ans&a[where]),where+1);
	dfs(deep,ans,where+1);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1)
	{
		sort(a,a+n,cmp);
		cout<<a[0];
		return 0;
	}
	if(n==m)
	{
		long long temp=a[0];
		for(int i=1;i<n;i++)
		{
			temp&=a[i];
		}
		cout<<temp;
		return 0;
	}
	dfs(0,0,0);
	cout<<sum; 
	return 0;
}
