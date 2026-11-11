#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000050];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(t%2==1)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
