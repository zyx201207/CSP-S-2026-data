#include<bits/stdc++.h>
using namespace std;
long long n,m,mj;
long long s[222222];
long long mmax=-22222;
bool f[222222]={0};
void dfs(long long k,long long bb)
{
	if(k==m)
	{
		mmax=max(mmax,bb); 
		return;
	}
	for(int i=k;i<=n;i++)
	{
		if(f[i]) continue;
		long long bbb=bb&s[i];
		f[i]=1;
		dfs(k+1,bbb);
		f[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		dfs(1,s[i]);
		f[i]=0;
	}
	cout<<mmax;
	return 0;
}
//5 3
//31 3 1 15 7
//six seven
