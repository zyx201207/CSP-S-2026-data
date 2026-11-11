#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20000005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int sum=a[n-1]&a[n-2];
	m-=2; 
	n-=2;
	while(m--) sum=a[n-1]&sum;
	cout<<sum;
	return 0;
}
