#include<bits/stdc++.h>
using namespace std;
long long i,j,c,t,n,d,x[200005],a[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>d;
		a[i]=n-d-1;
		for(j=1;j<=n;j++)
		{
			cin>>x[i];
		}
	}
	for(i=1;i<=t;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
