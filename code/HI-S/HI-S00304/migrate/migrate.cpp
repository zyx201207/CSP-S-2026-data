#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,a,b,step,p,x;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		cin>>a>>b;
		for(int i=3;i<=n;i++)
			cin>>x;
		step=b-a;
		p=d/step;
		cout<<n-2*p+1<<endl;
	}
	return 0;
}
