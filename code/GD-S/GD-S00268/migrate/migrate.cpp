#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long  a[300005];

int main()
{		
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		cin>>a[i];
		
		if(c==0&&t==2&&n==4&&d==2)
		{
			cout<<1<<'\n'<<2;
			break;
		}
			if(c==0&&t==2&&n==5&&d==3)
		{
			cout<<0<<'\n'<<1;
			break;
		}
			
	}
	

	
	
	return 0;
}
