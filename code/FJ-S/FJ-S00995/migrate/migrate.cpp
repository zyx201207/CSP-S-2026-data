#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t;
int n,d;
int x[MAXN];
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
		if(c==11||c==12)
		{
			int flag=0,ans1,ans2,y=d/(x[2]-x[1]);
			ans1=2+y;
			ans2=2*y;
			if(ans1>4)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<n-ans1+1<<endl;
			}
		}
	}
	return 0;
}
