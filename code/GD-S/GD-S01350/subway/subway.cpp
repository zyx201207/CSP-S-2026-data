#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		for(int j=1;j<=c*2;j++)cin>>m;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c>>m;
		cout<<a[m]<<"\n";
	}
}
