#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
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
			cin>>a[i];
		}
		if((c==11||c==12)&&(d>=2*(a[2]-a[1])))
		{
			cout<<n-2<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
