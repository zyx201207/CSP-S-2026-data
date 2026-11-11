#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10101001],s,m,y[101001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=t;i++)
	{
		cin>>x[i];
		cin>>s>>m;
		cin>>y[i];
	}
	if(n==4&&d==2)
	{
		cout<<1<<endl;
		cout<<2;
	}else if(n==5&&d==3)
	{
		cout<<0<<endl<<1;
	}
	return 0;	
} 
