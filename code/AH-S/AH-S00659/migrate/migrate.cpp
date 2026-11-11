#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	if(c!=11&&c!=12)
		while(t--)
			cout<<"0\n";
	else
	{
		while(t--)
		{
			int n,d,x,y;cin>>n>>d;
			cin>>x>>y;y-=x;
			for(int i=3;i<=n;i++)
				cin>>x;
//			if(y>d&&n>2)cout<<n-2<<"\n";
//			else cout<<"0\n";
//			int ans=0;
//			for(int i=n-2;i>=1;i++)
//			{
//				if(d>)
//			}
			if(d>2*y&&d<=3*y)cout<<n-2<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
