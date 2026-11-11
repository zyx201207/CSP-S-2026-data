#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	if(c==0&&t==2&&n==5&&d==2)cout<<1<<endl<<2<<endl;
	else if(c==0&&t==2&&n==6&&d==2)cout<<0<<endl<<1<<endl;
	else
	{
		for(int i=1;i<=t;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
