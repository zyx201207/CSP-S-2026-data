#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2001000],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n-3;i++)
			if(x[i+3]-x[i]>d&&x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i+2]<=d)
			 ans++;
		cout<<ans;
	}
	return 0;
}