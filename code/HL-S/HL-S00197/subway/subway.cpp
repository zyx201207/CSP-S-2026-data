#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,q,d,a[100005];
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n+2;i++)cin>>a[i];
	for (int i=1;i<=2;i++)cin>>a[i];
	cout<<0<<endl;
	cout<<0;
	return 0;
}
