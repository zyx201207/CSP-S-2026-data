#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=0;
int a[300005];
void s(int q,int cnt,int k)
{
	if(q>m)
	{
		maxn=max(maxn,cnt);
		return ;
	}
	if(q==1)
	{
		for(int i=1;i<n;i++)
		{
			s(q+1,a[i],i);
		}
	}
	else
	{
		for(int i=k+1;i<=n;i++)
		{
			s(q+1,(cnt&a[i]),i);
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	s(1,0,1);
	cout<<maxn;
	return 0;
}

