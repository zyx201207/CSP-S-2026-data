#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[100005];
long long sum[100005];
long long cnt[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		sort(cnt+1,cnt+n+1);
		cout<<cnt[n];
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		cout<<n;
		return 0;
	}
	sum[0]=0;
	sum[1]=a[1];
	sum[2]=a[2]+a[1];
	for(int i=1;i<=n;i++){
	sum[i]=sum[i-1]+a[i];
			for(int j=n;j>=1;j--)
		{
			if(a[n+1-i]*i-sum[i]<=m && a[n+1-i]*i-sum[i]>0)
		{
			cout<<n-i+1;
			return 0;
		}
		}
	}
	cout<<0;
}