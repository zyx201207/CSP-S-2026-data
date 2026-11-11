#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100000001],s;
void dfs(long long x,long long y,long long s1,long long b)
{
	if(x==k)
	{
		s=max(s,s1);
		return;
	}
	for(int i=y;i<=n;i++)
	{
		s1=b&=a[i];
		dfs(x+1,i+1,s1,a[i]);
	}
	return;
}
int main()
{
	ios::sync_with_stdio; 
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,1,a[1],a[1]);
	cout<<s;
	return 0; 
}
//4 2 3 15 12 12
