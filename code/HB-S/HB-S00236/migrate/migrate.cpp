#include <bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int c,t,n,d,x[maxn],a[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n-1;i++) a[i]=x[i+1]-x[i];
		if(a[1]<d/2&&a[1]>d/3)
		{
			int x=d/__gcd(a[1],d);
			cout<<(a[n]-a[1]-x)/a[1]+1;
		} 
	}
	return 0;
}
