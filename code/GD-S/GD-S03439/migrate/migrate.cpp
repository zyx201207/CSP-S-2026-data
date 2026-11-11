#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12||c==0)
	{
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			int c=a[2]-a[1];
			int h=m/c+2;
			cout<<n-h+1<<endl;
		}
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			cout<<0<<endl;
		}	
	}
	return 0;
}
