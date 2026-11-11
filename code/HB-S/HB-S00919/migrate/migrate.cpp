#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int ans=0;
int x[2222222];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int a=x[2]-x[1];
		int cnt=d/a;
		if(cnt==0)
		{
			ans=0;
		}
		else
		{
			if((n-3)>=0)
			{
				ans=n-3;
			}
			else
			{
				ans=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


