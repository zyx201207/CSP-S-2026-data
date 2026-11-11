#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n%d==0)
		{
			cout<<n/d-1<<endl;
		}
		else
		{
			cout<<n/d<<endl;
		}
	}
	return 0;
}
