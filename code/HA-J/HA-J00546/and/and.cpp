#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
bool cmp(ll a,ll b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum = a[1];
	for(int i = 2;i<=m;i++) sum = (sum & a[i]);
	cout<<sum;
	return 0;
}

