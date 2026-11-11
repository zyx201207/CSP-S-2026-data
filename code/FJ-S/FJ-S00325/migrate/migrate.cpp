#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[999999];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int b=d/(a[2]-a[1]);
		if(d<=a[2]-a[1])
			cout<<0<<endl;
		else
			cout<<max(n-2*b+1,0)<<endl;
	}
	return 0;
}

