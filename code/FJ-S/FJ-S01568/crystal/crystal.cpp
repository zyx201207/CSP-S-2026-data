#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int res=0;
	for(int i=1,l=0;i<=n;i++)
	{
		while(l<i&&(a[i]*(i-l)-(s[i]-s[l]))>m)l++;
		res=max(res,i-l);
	}
	cout<<res;
	return 0;
}
