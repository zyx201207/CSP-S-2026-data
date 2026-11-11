#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans;
long long dfs(long long x,long long y,long long z)
{
	if(y>n)
	{
		return x;
	}
	if(z>m)
	{
		return x;
	}
	if(x==0)
	{
		return max(dfs(0,y+1,z),dfs(a[y],y+1,z+1));
	}
	return max(dfs(x,y+1,z),dfs(x&a[y],y+1,z+1));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<dfs(0,1,0);
	return 0;
}
