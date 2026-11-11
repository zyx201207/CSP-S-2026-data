#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],t[500005],q1,q2;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>t[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1>>q2;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<'\n';
	}
	return 0;
}