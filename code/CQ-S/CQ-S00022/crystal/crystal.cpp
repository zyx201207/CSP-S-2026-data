#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int n,m;
int ans=0;
int dis[N],a[N];
int sum[N];
bool check(int mid)
{
	int p=mid-1;
	int num=0;
	for(int i=1;i<=p;i++) num+=dis[i]*i;
	if(num<=m) return true;
	else
	{
		for(int i=mid;i<=n;i++)
		{
			num+=dis[i]*p;
			num-=sum[i-1];
			num+=sum[i-p-1];
			if(num<=m) return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) dis[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+dis[i];
	int L=1,R=n+1;
	while(L<=R)
	{
		int mid=(L+R)/2;
		if(check(mid))
		{
			L=mid+1;
			ans=mid;
		}
		else R=mid-1; 
	}
	cout<<ans<<'\n';
	return 0;
}
//-3 -1 2 2 7
//  2 3 0 5
