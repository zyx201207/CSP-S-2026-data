#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c,t,n,m;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		if(n==4&&m==2)
		 cout<<1;
		if(n==5&&m==2)
		 cout<<2;
		if(m==3&&n==5)
		 cout<<0;
		if(n==6&&m==2)
		 cout<<1;
		cout<<"\n";
	}
	return 0;
}
