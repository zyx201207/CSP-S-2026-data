#include<bits/stdc++.h>
using namespace std;
int n,p,a[2000005],c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for (int qq=1;qq<=t;qq++)
	{
		int d;
		cin>>n>>d;
		int l=0;
		p=0;
		int q=0;
		int ee=-1e9,eeee=0;
		int ff=1e9;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ee=max(ee,a[i]);
			ff=min(ff,a[i]); 
		}
		p=a[2]-a[1];
		if (abs(a[1]-ee)<=d&&abs(a[1]-ff)<=d)
		{
			cout<<0<<endl;
			continue;
		}
		for (int i=2;i<=n;i++)
		{
			if (abs(a[i]-ee)<=d&&abs(a[i]-ff)<=d)
			{
				cout<<0<<endl;
				eeee=1; 
				break;
			}
			if (a[i]-a[i-1]==p)
			{
				l++;
			}
		}
		if (eeee==1)
		{
			continue;
		}
		int o=0;
		if (l+1==n)
		{
			for (int i=1;i<=n;i++)
			{
				o+=p;
				if (o>d)
				{
					q=i;
					break;
				}
			}
			cout<<n-q<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
	
}
