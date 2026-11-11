#include<bits/stdc++.h>
using namespace std;
long long n,m,a[511000],s[511000],ans=0;
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
	for(long long i=1,j=1;i<=n;i++)
	{
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		if(s[i]-s[j-1]-(a[i]-a[j])*(j-1)<=m)
		{
			ans=max(ans,i-j+1);
		}
		else
		{
			j++;
		}
	}
	cout<<ans;
	return 0;
}
