#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(ll i=1; i<m; i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
