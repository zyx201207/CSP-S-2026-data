#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=5e5+5;
int i,n,m,a[N],c[N],q[N],cnt,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)c[i]=a[i+1]-a[i];
	for(i=1;i<n;i++)
	{
		sum+=i*c[i];
		if(sum>m)break;
		cnt++;
	}
	cout<<cnt+1;
}
