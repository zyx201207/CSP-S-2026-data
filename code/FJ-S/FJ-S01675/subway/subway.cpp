#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500005],k[500005],a[500005],t[500005];
ll x[500005],y[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int i=1;i<=k[i];i++)
		{
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	return 0;
} 
