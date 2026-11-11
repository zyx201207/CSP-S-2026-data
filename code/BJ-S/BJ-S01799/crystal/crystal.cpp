#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned long long
#define i128 __int128
#define pii pair<int,int>
#define inf 1000000000
#define infl 1000000000000000000ll
#define ls (p<<1)
#define rd (p<<1|1)
const int N=5e5+5;
const int M=5;
int n,m,a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(l<i&&(i-l+1)*a[i]-(sum[i]-sum[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}