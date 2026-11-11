#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int c[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		int i,l;
		int ans=0;
		cin>>n>>d; 
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<4)
			cout<<0<<endl;
		else
		{
			int k=a[2]-a[1];
			if(k<2)
				k=2;
			for(i=k;i<=d;i++)
				ans=ans+n/i; 
		}
		cout<<ans/2;
	}
	return 0;
} 
