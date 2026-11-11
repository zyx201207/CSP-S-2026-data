#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d>=a[n]-a[1]||d<=a[2]-a[1]){cout<<0<<"\n";continue;}
		d/=a[2]-a[1];
		cout<<n-d*2+1<<"\n";
	}
}
