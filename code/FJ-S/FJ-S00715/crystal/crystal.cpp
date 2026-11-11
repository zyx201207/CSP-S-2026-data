#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[500007],s[500007];
int n,m,i;
bool check(int x)
{
	int cnt=i-x;
	if(a[i]*cnt-(s[i-1]-s[x-1])<=m) return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

