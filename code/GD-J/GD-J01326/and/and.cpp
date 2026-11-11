#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n-1;i>=n-m+1;i--)sum=(sum&a[i]);
	cout<<sum;
	return 0;
}
