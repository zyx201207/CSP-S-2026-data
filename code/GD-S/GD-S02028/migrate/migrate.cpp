#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],mn=1,cha;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mn=min(mn,a[i]);
		}
		if(mn<0)
		for(int i=1;i<=n;i++)
		{
			a[i]+=1-mn;
		}
		cha=a[2]-a[1];
		if(d<=cha)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			if(cha*n<=d)
			{
				cout<<0<<endl;
				continue;
			}
			cout<<n-(d/cha)*2+1<<endl;
		}
	}
}
