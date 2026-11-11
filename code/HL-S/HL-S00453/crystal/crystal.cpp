#include <bits/stdc++.h>
using namespace std;
int const N=1e6;
typedef long long ll;
ll f[N],sum[N],n,m;

ll check(int num)
{
	ll p=0;
	for(int i=1;i<=n-num+1;i++)
	{
		ll t=sum[i+num-1]-p,cnt=0;
		if(t<=m) return 1;
		cnt+=i;
		p=p+f[i+num]-f[i+num-1]*cnt+f[i+num]-f[i];
	}
	return 0;
}

int main()
{
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
    sort(f+1,f+n+1);
    for(int i=2;i<=n;i++) 
		sum[i]=sum[i-1]+(f[i]-f[i-1])*(i-1);
   	int l=1,r=n,mid,ans=1;
   	while(l<=r)
   	{
   		mid=(l+r)/2;
   		if(check(mid)) l=mid+1,ans=mid;
   		else r=mid-1;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}