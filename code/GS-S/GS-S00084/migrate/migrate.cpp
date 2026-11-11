#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[2000005],c,o;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
		}
		if(m>=a[n]-a[1])
		{
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12)
		{
			if(m<2*(a[2]-a[1]))
			cout<<0<<endl;
			continue;
		}
		cout<<m<<endl;
	}
	return 0;
 } 
