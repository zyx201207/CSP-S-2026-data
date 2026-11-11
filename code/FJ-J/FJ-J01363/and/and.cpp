#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
ll n,m,a[N],ans;
void f(ll i,ll t,ll cnt)
{
	if (t==m)
	{
		ans=max(ans,cnt);
		return ;
	}
	for (int j=i+1;j<=n;j++)
	{
		f(j,t+1,cnt&a[j]);
	}
	return ;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n-m+1;i++)
	{
		f(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}