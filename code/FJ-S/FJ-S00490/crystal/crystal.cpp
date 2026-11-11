#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,head,ans=1,sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	head=1;
	sum=a[1];
	for(int i=2;i<=n;i++)
	{
		while((i-head)*a[i]-sum>m)
		{
			sum-=a[head];
			head++;
			
		}
		sum+=a[i];
		ans=max(ans,i-head+1);
	}
	cout<<ans;
	return 0;
}
