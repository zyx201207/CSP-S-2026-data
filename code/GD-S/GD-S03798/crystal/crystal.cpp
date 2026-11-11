#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=1,j=1,sum=0;i<=n;i++)
	{
		sum+=a[i];
		for(;j<i&&a[i]*(i-j+1)-sum>m;)sum-=a[j++];
		mx=max(mx,i-j+1);
	}
	cout<<mx;
	return 0;
}
//14:45 done