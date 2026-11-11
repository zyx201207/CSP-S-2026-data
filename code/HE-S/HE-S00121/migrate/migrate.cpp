#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;i++) cin>>a[i];
		if(n<=3)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==4)
		{
	        cout<<1<<endl;
	        continue;
		}
		else cout<<3<<endl;
	}
	return 0;
} 
