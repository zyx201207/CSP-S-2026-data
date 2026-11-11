#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200500];
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
			cin>>a[i];
		}
		long long f = d/(a[1]-a[2]);
		f = f+2;
		cout<<n-f+1;
	}
}
