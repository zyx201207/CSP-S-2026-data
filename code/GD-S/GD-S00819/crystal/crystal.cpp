#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long g[N];
long long D[N];
long long sum[N];
long long cnt[N];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i]=a[i];
	}
	sort(g+1,g+1+n);
	sort(a+1,a+1+n);
	int nlen=unique(g+1,g+1+n)-g-1;
	for(int i=1;i<=n;i++)
	{
		D[i]=lower_bound(g+1,g+1+nlen,a[i])-g;
		cnt[D[i]]++;
		ans=max(cnt[D[i]],ans);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) continue;
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-1-mid+1)-(sum[i-1]-sum[mid-1])<=m) ans=max(ans,cnt[D[i]]+(i-mid)),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
