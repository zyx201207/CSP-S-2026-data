#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long now=0;
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&now+(j+1-i)*(a[j+1]-a[j])<=m)
		{
			now+=(j+1-i)*(a[j+1]-a[j]);
			j++;
		}
		ans=max(ans,j-i+1);
		now-=a[j]-a[i];
	}
	cout<<ans<<"\n";
	return 0;
}
