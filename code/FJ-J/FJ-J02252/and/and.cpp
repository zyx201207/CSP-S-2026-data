#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const int M = 3e5 + 10;
ll n, m;
ll a[N];
ll ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
