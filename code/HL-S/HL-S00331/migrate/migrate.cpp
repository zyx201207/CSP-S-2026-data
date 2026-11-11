#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[20000000],tc,co,n2,e;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		tc=0;
		n2=0;
		e=0;
		cin>>n>>d;
		if(n==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
			if(j==2) tc=x[j]-x[j-1];
		}
		
		n2=d/tc;
		if(n2<2||n+1-2*n2<0) e=0;
		else e=n+1-2*n2;
		cout<<e<<endl;
	}
	return 0;
}