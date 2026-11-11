#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005];
long long ans;
long long sum[5000005];
long long w;
long long cnt;
bool cmp(long long a,long long b){return a<b;}
bool check(long long k)
{
	if(m>=w-(a[k]*k-sum[k])) return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		w=a[i]*i-sum[i];
		long long l=1,r=i,p_ans=0x3f;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(check(mid)) r=mid-1,p_ans=mid;
			else l=mid+1;
		}
		ans=max(ans,i-p_ans+1);
	}
	cout<<ans;
	return 0;
}
