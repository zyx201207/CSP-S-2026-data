#include<bits/stdc++.h>
using namespace std;

long long a[200005],b[200005];

long long mp(long long a,long long b)
{
	return a>b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long ans,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,mp);
	for(int i=1;i<=m;i++)
	{
		b[i]=a[i];
	}
	ans=b[1];
	for(int i=2;i<=m;i++)
	{
		ans&=b[i];
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
