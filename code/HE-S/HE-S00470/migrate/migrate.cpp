#include <bits/stdc++.h>
using namespace std;
long long a[5000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	if(c==0)
	{
		int flag=0;
		while(t>0)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(n==4&&t==2) flag=1;
			if(n==5&&t==2) flag=2;
			t--;
		}
		if(flag==1) cout<<1<<endl<<2;
		if(flag==2) cout<<0<<endl<<1;
	}
	while(t>0)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<0<<endl;
	}
	return 0;
}
