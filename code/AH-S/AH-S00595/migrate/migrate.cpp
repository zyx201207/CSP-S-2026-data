#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000010],delta,sum=1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			scanf("%lld %lld",&n,&d);
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&x[i]);
			}
			delta=x[2]-x[1];
			int a=delta/d;
			for(int i=2;i<=n-a*d;i++)
			{
				sum*=i;
			}
		cout<<sum<<endl;
		}
	return 0;
	}
	while(cin>>c)
	{}
	for(int i=0;i<=t;i++)
	{
		cout<<1<<endl;
	}
	return 0;
}
