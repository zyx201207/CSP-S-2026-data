#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		int x[n+5];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i+3<=n;i++)
		{
			if(x[i+3]-x[i]>=2*d-1) ans++; 
		}
		cout<<ans<<endl;
	}
	return 0;
}


