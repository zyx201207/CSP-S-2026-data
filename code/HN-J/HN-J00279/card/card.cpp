#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
ll a[N];
ll t[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(t[i]>0)
		{
			cout<<t[i]<<' ';
			t[i]=0;
		}
	}
	return 0;
} 

