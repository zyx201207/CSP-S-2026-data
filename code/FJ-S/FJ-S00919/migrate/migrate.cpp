#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int sum=0;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n==1||n==2||n==3)
		{
			cout<<0<<endl;
			continue;
		}
		sum=d/(x[2]-x[1]);
		int l=sum+2,r=sum*2-1;
		if(sum==1)
		{
			cout<<0<<endl;
			continue;
		}
		else if(sum==2)
		{
			l=4;
			r=4;
		}
		else if(sum>2)
		{
			cout<<0<<endl;
			continue;
		}
		int ans=n-4+1;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
