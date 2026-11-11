#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll a[2000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,greater<ll>());
	cout<<a[n];
	return 0;
 }
