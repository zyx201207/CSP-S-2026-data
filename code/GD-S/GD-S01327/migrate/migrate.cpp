#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2001000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	while(t--)
	{
		bool t=0;
		cin>>n>>d;
		cin>>x[1]>>x[2];
		int c=x[2]-x[1];
		for(int i=3;i<=n;i++)
		{
			cin>>x[i];
			if(x[i]-x[i-1]!=c)
				t=1;
		}
		if(!t && c<=d)
			cout<<n-3;
	}
	return 0;
}
