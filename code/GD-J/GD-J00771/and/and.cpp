#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end(),greater<ll>());
	ll ans=a[0];
	for(int i=0;i<m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
