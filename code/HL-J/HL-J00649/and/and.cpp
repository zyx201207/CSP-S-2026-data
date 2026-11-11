#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[200010]={};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,greater<ll>());
	cout<<a[m-1];
	return 0;
}
