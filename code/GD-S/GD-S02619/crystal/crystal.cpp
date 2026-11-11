#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,ci=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(ci>m&&l<i)
		{
			ci+=a[l];
			ci-=a[i];
			l++;
		}
		ans=max(ans,i-l+1);
		ci+=(i-l+1)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
