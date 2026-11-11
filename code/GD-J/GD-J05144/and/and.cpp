#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
long long ans;
void dfs(long long st,long long p,long long uc,long long s)
{
	if(p>n)
	{
		ans=max(ans,s);
		return;
	}
	if(p!=st&&uc<n-m) dfs(st,p+1,uc+1,s);
	s&=a[p];
	dfs(st,p+1,uc,s);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[n];
	for(long long i=1;i<=n-m+1;i++)
		dfs(i,i,i-1,a[i]);
	cout<<ans;
	return 0;	
}
