#include<bits/stdc++.h>
using namespace std;
long long l,r,mid,n,m,a[500005],rocks;
long long check(long long x)
{
	long long ans=0,sum=0;
	for(int i=x;i>=1;i--)
	{
		ans+=a[x]-a[i];
		if(ans>m)
			return sum;
		sum++;
	}
	return sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			continue;
		rocks=max(rocks,check(i));
	}
	cout<<rocks;
}
