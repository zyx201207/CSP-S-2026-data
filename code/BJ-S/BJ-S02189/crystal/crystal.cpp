#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0,cnt2=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
		b[i]=a[i+1]-a[i];
	}
	for(int i=n;i>=1;i--)
    {
		long long sum=0;
		for(int j=i-1;j>=1;j--)
		{
			sum=sum*2+b[j];
			if(sum>m) break;
			cnt2++;
		}
		ans=max(ans,cnt2);
		cnt2=0;
	}
	cout<<ans+1;
return 0;
}
