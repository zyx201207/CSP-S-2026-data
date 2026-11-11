#include<bits/stdc++.h>
using namespace std;

int c,t;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			sum+=x;
		}
		cout<<sum/5<<endl;
	}
	
	return 0;
}
