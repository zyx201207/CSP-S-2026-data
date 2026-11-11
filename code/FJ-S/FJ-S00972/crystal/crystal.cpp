#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[114514*5],pre[114514*5],ans=0,j=2;
signed main()
{
  	freopen("crystal.in","r",stdin);
  	freopen("crystal.out","w",stdout);
  	ios::sync_with_stdio(false);
  	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int minn=a[1]-1;
	for(int i=1;i<=n;i++) a[i]-=minn,pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(a[j]*(j-i+1)-(pre[j]-pre[i-1])<=m&&j<n) j++;
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
}
