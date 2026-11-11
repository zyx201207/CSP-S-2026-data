#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],m,s;
void dfs(long long k,long long t,long long l)
{
	if(l==m)
	{
		s=max(s,t);
	}
	if(k>n) return;
	if(l==0) dfs(k+1,a[k],l+1);
	else dfs(k+1,(t&a[k]),l+1);
	dfs(k+1,t,l);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<s;
	return 0;
}
