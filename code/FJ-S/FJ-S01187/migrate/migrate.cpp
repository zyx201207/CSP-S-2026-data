#include<bits/stdc++.h>
using namespace std;
int c;
int t;
long long n,d;
long long a[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0)
	{
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[n]-a[1]<=d)cout<<0<<endl;
		if(a[2]-a[1]>=d && a[2]-a[1]<2*d)cout<<0<<endl;
		if(a[2]-a[1]>=2*d && a[2]-a[1]<3*d)cout<<n-3<<endl;
		if(a[2]-a[1]>=3*d && a[2]-a[1]<4*d)cout<<0<<endl;
		else cout<<1;
		
	}
	
	
	return 0;
}