#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=3e5;
ull a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ull ans=a[n];
	for(int i=n-1;i>n-m;i--)ans&=a[i];
	cout<<ans;
}
