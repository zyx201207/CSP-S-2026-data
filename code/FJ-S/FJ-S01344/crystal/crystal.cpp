#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],h=1,t=1,sum,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		while(sum+(a[i]-a[i-1])*(h-t+1)>m)
			sum=sum-(a[i-1]-a[t]),t++;
		sum=sum+(a[i]-a[i-1])*(h-t+1),h++,ans=max(ans,h-t+1);
	}
	cout<<ans;
	return 0;
}
