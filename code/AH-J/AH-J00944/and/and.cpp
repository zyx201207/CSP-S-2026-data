#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200010],b[200010],m=0;
void dfs(int step,int start) 
{
	if(step>k)
	{
		long long l=b[1];
		for(int i=2;i<=k;i++)
		{
			l=l&b[i];
		}
		m=max(l,m);
		return ;
	}
	for(int i=start;i<=n;i++)
	{
		b[step]=a[i];
		dfs(step+1,i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,1);
	cout<<m;
	return 0;
}
